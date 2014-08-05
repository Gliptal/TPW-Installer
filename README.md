TPW Installer
======

This small set of files act as a lightweight installer for the TPW MODS package. This collection was proven to be essential for a thorough enjoyement of [ArmA III](http://www.arma3.com/), thanks to the life it brings in what are otherwise barren and uninhabited islands.

`install.exe` (written in batch script and then converted to executable) will automatically copy all required files from the downloadable package to the correct Arma III folder: it queries the windows registry (thanks pettka!) to identify it; a shortcut to the GUI will also be created on the desktop.

`update.exe` (written in C++) is automatically called by the install script, and will update TPW_MODS.hpp and any saved presets with any changes specified by [tpw](http://forums.bistudio.com/member.php?62814-tpw): this means there will be no need for the end user to manually edit his (or hers) files to bring them to match.

Changelog
======

[2.0.0]

- [install.exe]
  - moved to .exe format
  - tweakings and enhancements

- [update.exe]
  - first working release

[1.0.0]

- [install.bat]
  - first working release

Setup
======

The file structure inside the main downloadable `.rar` must be:
```
@TPW_MODS
edits.txt
install.exe
shortcut.exe
update.exe
```

Usage
======

`update.exe` reads the commands written in `edits.txt` and executes them on all relevant files. The possible commands are the following:

- to add a variable after an existing variable
```
add
[new variable]
after
[existing variable]
```

- to add a variable before an existing variable
```
add
[new variable]
before
[existing variable]
```

- to remove a variable
```
remove
[existing variable]
```

- to modify a variable
```
change
[existing variable]
[modified variable]
```

In `edits.txt` the first line must be the number of edits being made (if no edits are to be made, the value should be `0`); a blank line must separate this number from the first edit and from each subsequent edit.

As `[existing variable]` only the first word (that is, up to the first space) on that variable's line must be specified. Spaces are obviously allowed in the `[new variable]` and `[existing variable]` parts. Also technically `a`, `r`, `c` are equivalent to `add`, `remove`, `change`; `a`, `b` are equivalent to `after`, `before`.

Limitations
======

- Currently the installer will place the mod in ArmA III's install directory, and not in any user specified mods directory.

Progress
======

25/07/14 | [1.0.0](https://github.com/Gliptal/TPW-Installer/tree/1.0.0) | first working release

05/08/14 | [2.0.0](https://github.com/Gliptal/TPW-Installer/tree/2.0.0) | update.exe added, various enhancements

Links
======

- [TPW MODS @ BI Forums](http://forums.bistudio.com/showthread.php?164304-TPW-MODS-enhanced-realism-immersion-for-Arma-3-SP)
- [tpw profile @ BI Forums](http://forums.bistudio.com/member.php?62814-tpw)
- [ArmA III official site](http://www.arma3.com/)

Credits
======

All credits for the TPW MODS package go to its author [tpw](http://forums.bistudio.com/member.php?62814-tpw). Special thanks go to Bohemia Interactive, that have proven to be one of, if not the best game studios around.

Thank you also to anyone that helped me in the BI Forums, be it a simple thanks or an helpful suggestion.

Special thanks to BI dev [pettka](http://forums.bistudio.com/member.php?71012-pettka) that helped me almost instantly.