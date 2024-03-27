"""Counts the floppies per second."""

import time

import numpy as np

N = 4096

if __name__ == "__main__":
    _rng = np.random.default_rng(0x2024_03_27)

    M1 = _rng.normal(0, 1, (N, N)).astype(np.float32)
    M2 = _rng.normal(0, 1, (N, N)).astype(np.float32)

    t0 = time.perf_counter()
    M3 = M1 @ M2
    t1 = time.perf_counter()

    gigafloppies = 2.0 * N * N * N / (t1 - t0) * 1e-9
    print(f"{gigafloppies=:.2f}")
