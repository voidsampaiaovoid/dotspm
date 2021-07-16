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

