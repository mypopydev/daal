/* file: SampleKmeansDense.java */
//==============================================================
//
// SAMPLE SOURCE CODE - SUBJECT TO THE TERMS OF SAMPLE CODE LICENSE AGREEMENT,
// http://software.intel.com/en-us/articles/intel-sample-source-code-license-agreement/
//
// Copyright 2017-2018 Intel Corporation
//
// THIS FILE IS PROVIDED "AS IS" WITH NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, NON-INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS.
//
// =============================================================

/*
 //  Content:
 //     Java sample of dense K-Means clustering
 ////////////////////////////////////////////////////////////////////////////////
 */

package DAAL;

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;

import org.apache.spark.api.java.*;
import org.apache.spark.api.java.function.*;
import org.apache.spark.SparkConf;

import scala.Tuple2;
import java.nio.DoubleBuffer;

import com.intel.daal.data_management.data.*;
import com.intel.daal.data_management.data_source.*;
import com.intel.daal.services.*;

public class SampleKmeansDense {
    public static void main(String[] args) {
        DaalContext context = new DaalContext();

        /* Create JavaSparkContext that loads defaults from the system properties and the classpath and sets the name */
        JavaSparkContext sc = new JavaSparkContext(new SparkConf().setAppName("Spark Kmeans"));

        /* Read from the distributed HDFS data set at a specified path */
        StringDataSource templateDataSource = new StringDataSource( context, "" );
        DistributedHDFSDataSet dd = new DistributedHDFSDataSet( "/Spark/KmeansDense/data/", templateDataSource );
        JavaPairRDD<Integer, HomogenNumericTable> dataRDD = dd.getAsPairRDD(sc);

        /* Compute k-means for dataRDD */
        SparkKmeansDense.KmeansResult result = SparkKmeansDense.runKmeans(context, dataRDD);

        /* Print the results */
        HomogenNumericTable Centroids  = result.centroids;
        printNumericTable("First 10 dimensions of centroids:", Centroids, 20, 10);

        context.dispose();
        sc.stop();
    }

    public static void printNumericTable(String header, NumericTable nt, long nPrintedRows, long nPrintedCols) {
        long nNtCols = nt.getNumberOfColumns();
        long nNtRows = nt.getNumberOfRows();
        long nRows = nNtRows;
        long nCols = nNtCols;

        if(nPrintedRows > 0) {
            nRows = Math.min(nNtRows, nPrintedRows);
        }

        DoubleBuffer result = DoubleBuffer.allocate((int)(nNtCols * nRows));
        result = nt.getBlockOfRows(0, nRows, result);

        if(nPrintedCols > 0) {
            nCols = Math.min(nNtCols, nPrintedCols);
        }

        StringBuilder builder = new StringBuilder();
        builder.append(header);
        builder.append("\n");
        for (long i = 0; i < nRows; i++) {
            for (long j = 0; j < nCols; j++) {
                String tmp = String.format("%-6.3f   ", result.get((int)(i * nNtCols + j)));
                builder.append(tmp);
            }
            builder.append("\n");
        }
        System.out.println(builder.toString());
    }
}
