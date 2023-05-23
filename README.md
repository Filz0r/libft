# 42 Libft
## This repository contains the libft I use on my 42 common core C projects

This is not the libft that you have to build for the first project, but it contains all of the functions we need to finish that project and some other that I'll add as time goes by in order to expand the functionalities of my libft project.
Right now I'm still figuring out how to add other projects like get_next_line and ft_printf to my libft. But essentially the point is to compile all my functions into libraries that are then linked together after being built and tested.
The structure will follow something like this:
```
├── includes
└── src
    ├── char <- functions that handle individual chars
    ├── fd <- functions that interact with file descriptors (gnl/printf not included)
    ├── lists <- funtions that handle lists (the bonus part of libft)
    ├── memory <- functions that create/manipulate memory
    ├── numbers <- functions that interact with int/long/float and math
    └── string <- functions that manipulate strings
```
and when you run `make all` make will build all the .o files into the **build** directory and after that link them all into the libft.a at the root of the repository.
As my libft grows new folders might be created for other functions I create as time goes by. While attending 42 this repo will always be Norm compliant, as it will be what I use to build my projects. 
Please try to not just copy and paste my code but try to understand how it works, and as usal keep on swimming! 
**NOTE:** At this initial stage I'm still not sure if my implementation of my Makefile is complient with the Norm, but to my understanding of it, it should be.
