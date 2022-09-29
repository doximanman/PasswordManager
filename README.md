# PasswordManager
A scuffed password manager!

## What can the manager do
The manager stores accounts - usernames and passwords - catagerized by sites.
The stored data can be accessed using various **commands**.

## Commands:
- **add <site> <username> <password>**: Add an account. needs 3 arguments, first argument is the site, second argument is the username, and 3rd is the password.
- **get <site> <username>**: Get the password of an account. First argument is the site, and the second argument is the account username.
- **remove <site> <username>(optional)**: Remove an account or a whole site. First argument is the site. if one argument is provided, it deletes the site.
- **show**: Shows the sites and usernames.
- **show full**: Shows the sites, usernames and passwords.
- **exit**: exit the program.

## How to run
first, compile using:
'''
g++ -std=c++11 src/*.cpp src/Command/*.cpp src/StaticLib/*.cpp -o PasswordManager.out
'''
then, run using:
'''
./PasswordManager.out
'''
