# Linux commands

## For zipping and unzipping

For zipping a directory and unzipping a zip file:

```sh
zip -r ./my_files.zip ./my_files

unzip ./my_files.zip
```

For encrypting and zipping a directory with a password:
```sh
zip --encrypt -r ./my_files.zip ./my_files

unzip ./my_files.zip    # This is ask for the password
```


