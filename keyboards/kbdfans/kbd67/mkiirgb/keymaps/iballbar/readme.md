# iballbar's KDB67 MKII Layout

* This is a three layer layout wih some consolidated functionality in the second and third layer.
* The keyboard is mostly used on macOS, but also on Linux and therefore it can swap ALT/CMD.
* There are additional CTRL keys for left and right when caps lock or enter key is held.
* Layers can be toggled (tap twice) or actived momentarily (hold).
* There are 2 seperate FN keys to activate layer 1 and 2 separately, indicated by different RGB colors.
* The main custom feature is using RGB to indicate the current active layer for each key. This is best achieved in solid color RGB modes.

## Layer 0

This is the base QUERTY layer.

* Grave is provided in the top right corner.
* Caps lock become FN2 when held.
* Primary Fn in the last row activates layer 1, indicated by hue shifted LED color.
* Secondary Fn right to the up arrow key activates layer 2, indicated by 2nd hue shifted LED color.

## Layer 1

This layer activates function keys and provides RGB controls. Keys acting on this layer are indicated by an LED color matching the current Fn key's LED color.

* Number keys become equivalent function keys.
* ESC becomes Grave.
* Grave becomes POWER (very useful on macOS only).
* Q toggles RGB.
* WASD for navigating through RGB modes and adjusting speed.
* <> control RGB saturation.
* Arrow keys shift hue and adjust brightness.
* PgUp, PgDown become HOME and END respectively.
* Backspace acts as delete, pipe as insert.

## Layer 2

This layer comprises most macOS media keys at the top row and some additional programming options. Keys acting on this layer are indicated by an LED color matching the current Fn key's LED color.

* N, M swap ALT/CMD for (N)ormal or (M)acOS.
* E resets (E)EPROM.
* R (R)esets keyboard.

![](https://i.imgur.com/sxJ1ocF.png)
# my-custom-kbd67mkiirgb

## complie 
```
qmk compile -kb kbdfans/kbd67/mkiirgb/v2 -km iballbar
```

## Before flash
### Put Your Keyboard Into DFU (Bootloader) Mode

In order to flash your custom firmware you have to put your keyboard into a special flashing mode. While it is in this mode you will not be able to type or otherwise use your keyboard. It is very important that you do not unplug your keyboard or otherwise interrupt the flashing process while the firmware is being written.

Different keyboards have different ways to enter this special mode. If your PCB currently runs QMK or TMK and you have not been given specific instructions try the following, in order:

* Hold down the `RESET` button (mo(1) + \)

If not working try: 
* Hold down both shift keys and press `Pause`
* Hold down both shift keys and press `B`
* Unplug your keyboard, hold down the Spacebar and `B` at the same time, plug in your keyboard and wait a second before releasing the keys
* Press the physical `RESET` button on the bottom of the PCB
* Locate header pins on the PCB labeled `BOOT0` or `RESET`, short those together while plugging your PCB in

When you are successful you will see a message similar to this in QMK Toolbox:

```
*** Atmel DFU device connected: ATMEL ATm32U4DFU (03EB:2FF4:0000)
```

### Flash Your Keyboard
via command line
```
qmk flash -kb kbdfans/kbd67/mkiirgb/v2 -km iballbar 
```

via QMK Toolbox

Click the `Flash` button in QMK Toolbox. 

You will see output similar to the following:

```
*** Making kbdfans/kbd67/mkiirgb/v2 with keymap iballbar and target flash

*** Attempting to flash, please don't remove device
Copying kbdfans_kbd67_mkiirgb_v2_iballbar.hex to qmk_firmware folder                                [OK]
Checking file size of kbdfans_kbd67_mkiirgb_v2_iballbar.hex                                         [OK]
 * The firmware size is fine - 27208/28672 (94%, 1464 bytes free)
Bootloader not found. Make sure the board is in bootloader mode. See https://docs.qmk.fm/#/newbs_flashing
 Trying again every 0.5s (Ctrl+C to cancel)...............................
Bootloader Version: 0x00 (0)
Erasing flash...  Success
Checking memory from 0x0 to 0x6FFF...  Empty.
0%                            100%  Programming 0x6A80 bytes...
[>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
0%                            100%  Reading 0x7000 bytes...
[>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
Validating...  Success
0x6A80 bytes written into 0x7000 bytes memory (95.09%).
    
*** Atmel DFU device disconnected: ATMEL ATm32U4DFU (03EB:2FF4:0000)
```


