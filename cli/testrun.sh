#!/bin/bash
IMG1=/home/developer/projects/datasets/iris/CASIA-Iris-Interval/001/L/S1001L01.jpg
IMG2=/home/developer/projects/datasets/iris/CASIA-Iris-Interval/001/L/S1001L06.jpg

build/IrisCompareCli -b $IMG1 -t $IMG2
