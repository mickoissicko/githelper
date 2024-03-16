![](assets/gelper.png)
<p align="center">
    <em>"it's pronounced gelper and not jelqer!"</em>
</p>

# Gelper
Gelper, or Git Helper is a cool tool if you do not want to use the default Git system for committing. In my opinion, I think Git's default system is pretty slow.

Gelper is here to help! It speeds up committing because it uses it's own system (you still need Git installed).

Gelper makes two files, `commit` and `addfiles`. The files are read procedurally, meaning:

Contents of `commit`:
```
This is a custom commit message on Line 1
This is another commit message on Line 2
```

Contents of `addfiles`:
```
custom_file_line_1.txt
custom_file_line_2.png
```

When you save the files and enter 'Y' when prompted if you are done, and when it pushes the changes, on Github, the files `custom_file_line_1.txt` with the commit mesage `This is a custom commit message on Line 1` will be added. The same can be said for `custom_file_line_2.png`

The filenames are encased in [ and ], so you don't need to add those. There is no extra formatting to be done. I will add an option for that later, but for now, this is all you get. And it's very fast to use.

# Usage
1. Download Git from [Git SCM downloads](https://git-scm.com/download)
2. Download [Gelper](https://github.com/mickoissicko/githelper/releases)
3. Open Gelper, and type '2' to go to the configure menu
4. Set desired preferences
5. Type '1' to start

## Info
Contents of 'cfg/pref.yml' should look like this:
```
# By default, both flags are set to True
MakeFiles: True
Cleanup: True
# Change the value of MakeFiles to false if: 
# You do not want the program to automatically make 'commit' and 'addfiles' files
# Change it to true if you do want that behaviour
#
# The cleanup flag just deletes those files upon exit
```

If MakeFiles is set to true, then:
- Gelper automatically creates a file `commit` and `addfiles` on startup

If Cleanup is set to true, then:
- Gelper automatically removes the files `commit` and `addfiles` after committing changes


