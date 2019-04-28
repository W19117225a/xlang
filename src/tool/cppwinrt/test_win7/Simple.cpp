#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

TEST_CASE("Simple")
{
    hstring a = L"hello";
    assert(a == L"hello");

    hstring b = a;
    assert(b == L"hello");

    try
    {
        throw hresult_error(E_FAIL, L"test");
        REQUIRE(false);
    }
    catch (hresult_error const& e)
    {
        REQUIRE(e.code() == E_FAIL);
        REQUIRE(e.message() == L"test");
    }
}
