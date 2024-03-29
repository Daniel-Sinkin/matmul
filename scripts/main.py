"""
Using python's numpy library to generate test data to verify our C implementation
against.
"""

import numpy as np


def check_dimensions():
    """Main"""
    _rng = np.random.default_rng(0x2023_03_26)

    M = np.array(
        [
            [1, 2, 3],
            [6, 7, 8],
        ],
        dtype=np.int32,
    )

    N = np.array(
        [
            [1, 2, -1],
            [3, 4, -2],
            [5, 6, -3],
        ],
        dtype=np.int32,
    )

    print(M)
    print(M.shape)
    print()
    print(N)
    print(N.shape)
    print()
    print(np.matmul(M, N))


def main(N=16):
    _rng = np.random.default_rng(0x2023_03_26)

    A = _rng.normal(3.0, 2.5, size=(N, N)).astype(np.float32)
    B = _rng.normal(2.0, 1.5, size=(N, N)).astype(np.float32)

    np.save("A.npy", A)
    np.save("B.npy", B)


if __name__ == "__main__":
    main()
