# dotspm
A package-manager like program to dotfiles written in C++ and shell script 

# Build

Execute:

```git clone https://github.com/voidsampaiaovoid/dotspm.git```

```cd dotspm```

```make```

# Usage

* To see valid parameters execute:

```./dotspm --help```

and will be returned:

```
dotspm: A package-manager like to Dotfiles
Usage:
	dotspm [ parameter ] [ name ]
Parameters:
	[ --help ]  [ --install ]
	[ --remove ]  [ --search ]
	[ --list ]
```

* To search dotfiles execute:

```./dotspm --search ${NAME}```

* To list all available dotfiles execute:

```./dotspm --list```

* To install dotfiles execute:

```./dotspm --install ${NAME}```

* To remove dotfiles execute:

```./dotspm --remove ${NAME}```

* Contributing

If you want to add more dotfiles to repository:

* edit file repo.xml, the basic structure should be like:
```
<repo>
	<package name="${NAME_OF_DOTFILES}" repo="${LINK_FOR_YOUR_DOTFILES('FROM GITHUB OR GITLAB')} dir="${NAME_OF_DIR_AFTER_GIT-CLONE}" command="${NAME_OF_SCRIPT_OF_INSTALLATION_OF_YOUR_DOTFILES}" remove="${NAME_OF_SCRIPT_OF_REMOVAL_OF_YOUR_DOTFILES}" comment="${A_COMMENT_ABOUT_YOUR_DOTFILES}" version="${VERSION_OF_YOUR_DOTFILES}"/>
</repo>
```

to do this, you have to create a commit or a fork.
