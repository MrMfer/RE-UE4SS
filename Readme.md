# Re-Host of Unreal Engine 4 Scripting System

## The original creator no longer wishes to be involved in or connected to this project.  Please respect their wishes, and avoid using their past usernames in connection with this project.

## Build requirements

- A computer running Windows.
  - Linux support might happen at some point but not soon.
- A version of MSVC that supports C++20, including std::format.
  - Visual Studio 2019 (recent versions), and Visual Studio 2022 will work.
  - More compilers will hopefully be supported in the future.


## Build instructions

1. Clone the repo.
2. Execute this command: `git submodule update --init --recursive`  
    Do not use the `--remote` option because that will force third-party dependencies to update to the latest commit, and that can break things.
3. There are three different ways you can build UE4SS.  
    1. Execute this command: `build_auto.bat <BuildMode> <Target>`, example: `build_auto.bat Release ue4ss`  
        Valid build modes are `Release` and `Debug`, and valid targets are `ue4ss` and `xinput1_3`.  
        Parallel compilation is enabled for this build method.
    2. Open the root UE4SS directory in CLion, select `ue4ss` or `xinput1_3` from the target list and hit the build button.  
        Parallel compilation is **NOT** enabled for this build method.
    3. Execute `VS_Solution/generate_vs_solution.bat` to generate a Visual Studio solution file.  
        Open the solution with Visual Studio 2019 or Visual Studio 2022, select the build type and build the `ue4ss` project.  
        Parallel compilation is enabled for this build method.
    
## Updating dependencies

If you want to update dependencies, you do so one of three ways:
1. You can execute `remote_update_first_party_submodules.bat` to update all first-party dependencies.  
2. You can also choose to update dependencies one by one, by executing `git submodule update --init --recursive vendor/<RepoOwner>/<Repo>`.  
    Remember to not use the `--remote` option unless you actually want to update to the latest commit.  
3. If you would rather pick a specific commit or branch to update a dependency to then `cd` into the submodule directory for that dependency and execute `git checkout <branch name or commit>`.

Note that you should also commit & push the submodules that you've updated if the reason why you updated was not because someone else pushed an update, and you're just catching up to it.

## Links

[Full installation guide](https://github.com/UE4SS/UE4SS/blob/master/Guides/FullInstallationGuide.md)  
[Fixing compatibility problems](https://github.com/UE4SS/UE4SS/blob/master/Guides/FixingBrokenAOBs.md)

## Credits

- **Original Creator** The original creator no longer wishes to be involved in or connected to  this project.  Please respect their wishes, and avoid using their past usernames in connection with this project.
- **Archengius**
  - UHT compatible header generator
- **CasualGamer**
  - Injector code & aob scanner is heavily based on his work, 90% of that code is his.
- **SunBeam**
  - Extra signature for function 'GetFullName' for UE4.25.
  - Regex to check for proper signature format when loaded from ini.
  - Lots and lots of work on signatures
- **tomsa**
  - const char* to vector\<int> converter
    - tomsa: Idea & most of the code
    - Original Creator: Nibblet support
- **boop** / **usize**
  - New UFunction hook method
- **Narknon**
  - Certain features and maintenance/rehosting of the project

## Thanks to everyone who helped with testing

- GreenHouse
- Otis_Inf
- SunBeam
- Motoson
- hooter
- Synopis