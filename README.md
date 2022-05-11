# CameraWebServer-still
This is a modified version of this Arduino IDE ESP32-CAM CameraWebServer example:

    File/Examples/ESP32/Camera/CameraWebServer 

The difference is that once you compile and upload the project, and get the camera web server URL via 'reset' and the Serial Monitor, 
you can run `curl` from the command line and capture a single still image:

`curl `*URL*`/capture >`*image-file*``

where *image* has the form `image.jpg`.
and *URL* comes from the Aduino IDE Serial Monitor window.
You must put your Wifi SSID and password in CameraWebServer-still.ino.

## `curltest`

There is also a c++ program `curltest.cpp` that tests the return code from 
`system("curl `*URL*`/capture` *arguments`)`
for later use in running `curl` from `system` inside a c++ program and testing the return code for success.
The usage is:

`./curltest `*URL* *image-file*

where *image* has the form `image.jpg`.
