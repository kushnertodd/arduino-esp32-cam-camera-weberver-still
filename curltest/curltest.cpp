/*
 program to test return codes of curl
 sample usage:
    curltest "http://10.33.32.20/capture" image.jpg");
  required:
    CameraWebServer-still is uploaded and running
*/

#include <iostream>
using namespace std;
int main(int argc, char **argv) {

  if (argc < 3)
    cout << "usage: " << argv[0] << " url image.jpg" << endl;
  else {
    char *url = argv[1];
    char *img_file = argv[2];
    //cout << "url " << url << " img_file " << img_file << endl;

    // succeeding curl command
    char curl_cmd[100];
    sprintf(curl_cmd, "curl %s/capture >%s >/dev/null 2>/dev/null", url, img_file);
    cout << "succeeding curl command '" << curl_cmd << "'" << endl;
    int works = system(curl_cmd);
    cout << "curl status code if works " << works << endl;

    // failing curl command
    int fails = system("curl foo >/dev/null 2>/dev/null");
    cout << "failing curl command: 'curl foo >/dev/null 2>/dev/null'" << endl;
    cout << "curl status code if fails " << fails << endl;
  }
}
