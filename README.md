[![Conventional Commits](https://img.shields.io/badge/Conventional%20Commits-1.0.0-%23FE5196?logo=conventionalcommits&logoColor=white)](https://conventionalcommits.org)
# Git Snippets

#### !This info is refering to the previous version of the solution, this version is stored in the `old-ahk` branch.
#### We are working right now for updating the project, changing to C++ and making a more elaborated product.

This script provide a group of **snippets** for making faster and easier work with **Git** in a **Terminal**. After you type the snippet just press **Space** and the right **Git Command** will be typed.

## Symbology
**@** : Optional Parameter <br>
**#** : Mandatory Parameter

| Snippet   | Command                   | Parameters            |
| --------- | ------------------------- | --------------------- |
| **Main Stream**                                               |
| gst       | *git status*              |                       |
| gad       | *git add .*               |                       |
| gcom      | *git commit -m "<#>"*     | Commit Message        |
|**Branching**                                                  |
|gbr        |*git branch <@>*           | Branch ID             |
|gsw        |*git switch <#>*           | Branch ID             |
|gmer       |*git merge <#>*            | Branch ID             |
|**Remote**                                                     |
|gft        |*git fetch <@> <@>*        | Remote ID & Branch ID |
|gpul       |*git pull <@> <@>*         | Remote ID & Branch ID |
|gpush      |*git push <@> <@>*         | Remote ID & Branch ID |
|gclon      |*git clone <#>*            | Link of remote repo   |
|grm        |*git remote*               |                       |
|grmad      |*git remote add <@>*       | Link of remote repo   |
|gset       |*git push -u origin <#>*   | Branch ID             |
|**Configuration**                                              |
|gconf      |*git config --global -e*   |                       |
|gconfl     |*git config --local -e*    |                       |
|**Others**                                                     |
|glog       |*git log --oneline*        |                       |
