@echo off
rem==============================================================
rem
rem SAMPLE SOURCE CODE - SUBJECT TO THE TERMS OF SAMPLE CODE LICENSE AGREEMENT,
rem http://software.intel.com/en-us/articles/intel-sample-source-code-license-agreement/
rem
rem Copyright 2017-2018 Intel Corporation
rem
rem THIS FILE IS PROVIDED "AS IS" WITH NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
rem NOT LIMITED TO ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
rem PURPOSE, NON-INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS.
rem
rem =============================================================

::  Content:
::     Intel(R) Data Analytics Acceleration Library samples list
::******************************************************************************

set MPI_SAMPLE_LIST=svd_fast_distributed_mpi                      ^
                    qr_fast_distributed_mpi                       ^
                    linear_regression_norm_eq_distributed_mpi     ^
                    linear_regression_qr_distributed_mpi          ^
                    pca_correlation_dense_distributed_mpi         ^
                    pca_correlation_csr_distributed_mpi           ^
                    pca_svd_distributed_mpi                       ^
                    covariance_dense_distributed_mpi              ^
                    covariance_csr_distributed_mpi                ^
                    multinomial_naive_bayes_dense_distributed_mpi ^
                    multinomial_naive_bayes_csr_distributed_mpi   ^
                    kmeans_dense_distributed_mpi                  ^
                    kmeans_csr_distributed_mpi                    ^
                    kmeans_init_dense_distributed_mpi             ^
                    kmeans_init_csr_distributed_mpi               ^
                    low_order_moments_csr_distributed_mpi         ^
                    low_order_moments_dense_distributed_mpi       ^
                    implicit_als_csr_distributed_mpi              ^
                    ridge_regression_norm_eq_distributed_mpi      ^
                    neural_net_dense_distributed_mpi              ^
                    neural_net_dense_allgather_distributed_mpi    ^
                    neural_net_dense_asynch_distributed_mpi
