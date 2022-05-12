#!/bin/bash
if [ -z "$2" ] ; then
  echo usage: $0 url image_root
  exit
fi
url=$1
image_root=$2
echo curl $url/capture \>${image_root}.jpg
curl $url/capture >${image_root}.jpg 2>/dev/null
echo jpegtran -grayscale -outfile ${image_root}-gray.jpg ${image_root}.jpg
jpegtran -grayscale -outfile ${image_root}-gray.jpg ${image_root}.jpg
