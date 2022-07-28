# CameraWebServer-still
This is a modified version of this Arduino IDE ESP32-CAM CameraWebServer example from:

    File/Examples/ESP32/Camera/CameraWebServer 

that allows capturing a ESP32-CAM image to a file from the command line.

The steps to use are:
- put your Wifi SSID and password in `CameraWebServer-still.ino`
- compile and upload to the ESP32-CAM in Arduino IDE
- get the camera web server *URL* after 'reset' from the Serial Monitor
- run `curl` from the command line to capture a single still image:

`curl `*URL*`/capture >`*image-file.jpg*

## Convert the color output jpeg image to grayscale 
The camera image software runs only on grayscale images
and ESP32-CAM images are color.

- Build and install the C [`jpegsrc.v`*version*`.tar.gz`](http://www.ijg.org/files/jpegsrc.v9e.tar.gz) 
library for jpeg image reading/writing.

- Run with this command to convert the image from color to grayscale:

`jpegtran -grayscale -outfile` *outfile.jpg* *infile.jpg*

## `camera_capture.sh`

This script does both of the above after installing the `ijg.org` library. 
It captures an image and converts it to grayscale. 

The usage is

`./camera_capture.sh `*URL* *image-root*

where

- *URL* is as above
- *image-root* is the root of the output filename

and it produces:
- *image-root*.jpg is the color image from the capture
- *image-root*-gray.jpg is the grayscale version of that image

so running

`./camera_capture.sh http://10.33.32.20 image`

produces the color image file `image.jpg` and the grayscale image file `image-gray.jpg`.

## Hardware
This is a good [ESP32-CAM board](https://smile.amazon.com/dp/B0924JR8RZ?ref=nb_sb_ss_w_as-reorder-t1_ypp_rep_k0_1_5&amp&crid=3VXS06IO2BU36&amp&sprefix=esp32) to get. 
[This](https://randomnerdtutorials.com/upload-code-esp32-cam-mb-usb/) shows how to hook the board into a computer via micro-USB, download the Arduino IDE to set up the camera. You can then download this software into the Arduino IDE and continue the steps from above.
