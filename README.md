# matmul
Learning C Programming and SIMD intrinsics while implementing (somewhat) efficient matrix multiplication.

## References
* Main inspiration
    * George Hotz Stream of 2022-06-25.
        * https://www.youtube.com/watch?v=VgSQ1GOC86s
* General Performance
    * https://www.youtube.com/watch?v=QGYvbsHDPxo
    * Handmade Hero 112 - A Mental Model of CPU Performance
        * https://www.youtube.com/watch?v=qin-Eps3U_E
    * CppCon 2018 - "Design for Performance" by Fedor Pikus
* On SIMD Intrinsics
    * Handmade Hero 115 - SIMD Basics
    * Intel SIMD Intrinsics
        * https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
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