# Steps required to get a project running in ESP32C6

After the installation process, follow the following steps:

1. Set the required environment variables for the shell by running:

```sh
get_idf
```

2. You can copy an example sample project provided by ESP IDF:

```sh
cp -r $IDF_PATH/examples/<<PROJECT_NAME>>
```

3. Run the following command before and after plugging in the ESP32C6 and look
   for the difference in these two outputs to find the port associated with
   ESP32C6:

```sh
ls /dev/tty*
```

4. (Optional: You may not need this step) Get proper permissions for the port:

```sh
sudo chmod a+rw /dev/tty<<ESP32C6_PORT_NAME>>
```

5. Enter the copied example project directory by running `cd` and then set the
   target to the ESP32C6:

```sh
idf.py set-target esp32c6
```

6. Now, compile and flash the project:

```sh
idf.py -p /dev/tty<<ESP32C6_PORT_NAME>> flash
```

The `flash` command will automatically compile and flash the project to the
ESP32C6. No need to manually run the `build` command.

7. Finally, monitor the port to see the ESP32C6's output:

```sh
idf.py -p /dev/tty<<ESP32C6_PORT_NAME>> monitor
```

If you encounter an error in this step, please repeat step-4 and try this step
again. It should do the trick.
