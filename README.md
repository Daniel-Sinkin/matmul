# matmul
Learning C Programming and SIMD intrinsics while implementing (somewhat) efficient matrix multiplication.

## References and Literature
* Videos
    * Main inspiration
        * George Hotz Stream of 2022-06-25.
            * https://www.youtube.com/watch?v=VgSQ1GOC86s
            * https://github.com/tinygrad/tinygrad/tree/68ca4d4276718f84a23400e53fea6ee7a1e3114a/extra/gemm
    * General Performance
        * Handmade Hero 112 - A Mental Model of CPU Performance
            * https://www.youtube.com/watch?v=qin-Eps3U_E
        * CppCon 2018 - "Design for Performance" by Fedor Pikus
        * Adding Nested Loops Makes this Algorithm 120x FASTER?
            * https://www.youtube.com/watch?v=QGYvbsHDPxo
    * On SIMD Intrinsics
        * Handmade Hero 115 - SIMD Basics
        * University of Queensland - SIMD and vectorization using AVX intrinsic functions
            * https://www.youtube.com/watch?v=AT5nuQQO96o
        * ETH Zürich - Digital Design & Computer Architecture - Lecture 20: SIMD Processors
            * https://www.youtube.com/watch?v=fP4kZ2Zx_84
        * CppCon 2023 - "Advanced SIMD Algorithms in Pictures" by Denis Yaroshevskiy
            * https://www.youtube.com/watch?v=YolkGP-rb3U
    * General C Programming
        * How I Program C
            * https://www.youtube.com/watch?v=443UNeGrFoM
        * Advanced C: The UB and optimizations that trick good programmers.
            * https://www.youtube.com/watch?v=w3_e9vZj7D8
        * How to Write Function-Like Preprocessor Macros (C example)
            * https://www.youtube.com/watch?v=w3iXBUbq4NY
* References
    * ARM NEON intrinsics
        * This is what Apple Silicone uses, so those are what we'll be implementing
        * https://developer.arm.com/architectures/instruction-sets/intrinsics/#f:@navigationhierarchiessimdisa=[Neon]
    * Oracle Instruction Set Mapping: AVX2
        * https://docs.oracle.com/cd/E36784_01/html/E36859/gntae.html#scrolltoc
    * Intel SIMD Intrinsics
        * https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
* Literature
    * Multiplying Matrices without Multiplying
        * https://arxiv.org/abs/2106.10860