#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <array>
#include <mincemeat.hpp>
#include <ranges>
#include <span>

TEST_CASE("sha256") {
	using namespace mincemeat;

	CHECK(to_string(sha256("abc")) == "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
	CHECK(to_string(sha256("")) == "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
	CHECK(
		to_string(sha256("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq")) ==
		"248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"
	);
	CHECK(
		to_string(sha256("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnop"
						 "qrsmnopqrstnopqrstu")) == "cf5b16a778af8380036ce59e7b0492370b249b11e8f07a51afac45037afee9d1"
	);
}

TEST_CASE("sha256 stream") {
	using namespace mincemeat;

	sha256_stream hasher;
	std::array<char, 1000> scream;
	scream.fill('a');

	for (int i = 0; i < 1000; i++) {
		hasher << scream;
	}

	CHECK(to_string(hasher.finish()) == "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0");
}
