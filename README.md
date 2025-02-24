![AgOpenGPS](media/agopengps%20name%20logo.png)
[AOG Download](https://github.com/agopengps-official/AgOpenGPS/releases)<br>
[AOG Forum](https://discourse.agopengps.com/)<br>
[AOG YouTube](https://youtube.com/@AgOpenGPS)

# 100hz RVC firmware for new All-In-One "Next Generation" PCB 
### *** very alpha/testing/dev stage ***

### Project Overview
This firmware is for the new [AiO-NextGen PCB](https://github.com/AgOpenGPS-Official/Board_Teensy_AiO-NextGen), with code copied from the official [All-In-One v4.x I2C](https://github.com/AgOpenGPS-Official/Firmware_Teensy_AiO-v4_I2C) firmware, more code copied from the ["Ace"](https://github.com/farmerbriantee/Ace) project and as is common for Arduino projects, the Internet. We hope to release the design files sometime in 2025. It is built on a bare metal [Mongoose](https://mongoose.ws/documentation) base which includes the TCP/UDP stack and a Web UI designed with the [Mongoose Wizard](https://mongoose.ws/wizard/#/). Mongoose [Discord Chat](https://discord.com/channels/1194962781745709128/1194962781745709131) is here. To start, we plan to support the usual v4.x AiO settings/options/operations via AOG's UI & PGNs with plans to add new settings in the Teesny's hosted Web UI to support the new board's capabilities (analog WORK input, RGB status LEDs brightness, RS232 NMEA output, Section/Machine control, speaker/buzzer, external RS232 IMU, ESP32 WiFi Bridge, AutoSteer Kickout options, etc).

### To Do
Hardware design/testing needs finalizing. Then the firmware can be finalized to support the basic AOG functions similar to the previous AiO boards.
Then as time allows, new features & UI design will be worked on.

### To Contribute
There is a lot of active dev work expected in the next few months. Here are some guidelines for contributing.

1) Main is reserved for the latest tested release, it should always work (except for unknown bugs😉).
2) Develop is where we make changes, adding new features and fixing bugs, it's like a "nightly" release, good for testing. So to contribute, branch off Develop, make some changes, make a PR back to Develop and get it reviewed.
3) Open an Issue for bug reports & feature requests

![PCB 3D Top](media/top%202d.png)
![PCB 2D Top](media/top%203d.png)

