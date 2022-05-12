# CameraWebServer-still
This is a modified version of this Arduino IDE ESP32-CAM CameraWebServer example from:

    File/Examples/ESP32/Camera/CameraWebServer 

that allows capturing a file from the command line.

The steps to use are:
- put your Wifi SSID and password in `CameraWebServer-still.ino`
- compile and upload the project in Arduino IDE
- get the camera web server *URL* after 'reset' from the Serial Monitor
- run `curl` from the command line to capture a single still image:

`curl `*URL*/capture `>`*image-file.jpg*

## Convert the color output jpeg image to grayscale 
The camera image software runs only on grayscale images
and ESP32-CAM images are color.
Build and install the C [`jpegsrc.v`*version*`.tar.gz`](http://www.ijg.org/files/jpegsrc.v9e.tar.gz) 
library for jpeg image reading/writing.

Run with this command to convert the image from color to grayscale:

`jpegtran -grayscale -outfile` *outfile.jpg* *infile.jpg*

## `camera_capture.sh`

This script does both of the above, captures an image and converts it to grayscale. 

The usage is

`./camera_capture.sh `*URL* *image-root*

where

- *URL* is as above
- *image-root* is the root of the output filename

and it produces:
- *image-root.jpg* is the color image from the capture
- *image-root-gray.jpg* is the grayscale version of that image

so running

`./camera_capture.sh http://10.33.32.20 temp`

produces the color image file `temp.jpg` and the grayscale image file `temp-gray.jpg`.

