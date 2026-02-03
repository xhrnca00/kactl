/**
 * Author: HaroldVemeno
 * Date: 2025-03-12
 * Source: p.\ 5 of Marsaglia, "Xorshift RNGs"
 * Description: Random number generator, algorithm "xor128"
 * from p.\ 5 of Marsaglia, "Xorshift RNGs".
 * Usage: rng_state state{};
 * uint32_t rv = rng(state);
 * Status: unknown
 */
#pragma once

using rng_state = array<uint32_t, 4>;

uint32_t rng(rng_state& state) {
    // Perform a contrived 32-bit shift
    uint32_t t = state[3];
    uint32_t s = state[0];
    state[3] = state[2];
    state[2] = state[1];
    state[1] = s;
    t ^= t << 11;
    t ^= t >> 8;
    return state[0] = t ^ s ^ (s >> 19);
}
