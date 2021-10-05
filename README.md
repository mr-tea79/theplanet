# The Planet
An adventure game in C/C++ SDL2 to help people who always dreamed of making a point and click adventure game but don't know where to begin.
This is being developed in my spare time and by no means finished. This is aimed at people who are learning to program and need a template to get started with making a game. There is lots of scope for improvement of the code, so have fun with it! You will learn more about coding if you are making something that is fun to do, trust me!



You are free to use this source code to make improvements, new games, anything! I just ask that you keep my name in the code as a nod of acknowledgement to all the many hours of work making this.

If you have enjoyed this and it has helped you get started using SDL2, please feel free to make a small donation via this link below: 

[Donate Here](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=8TW9LN5YTRBKL)



You will need the following libraries which can be downloaded. One is for dealing with images and the other for text. I have included them in the repo but just incase:

#SDL_image   (For images)
https://sites.google.com/site/sdlinvc2010/installation/sdl_image

#SDL_ttf    (For text)
https://sites.google.com/site/sdlinvc2010/installation/sdl_ttf

#sqlite3    (For inventory)
https://dcravey.wordpress.com/2011/03/21/using-sqlite-in-a-visual-c-application/

# You might need to point visual studio directories to the location of the libraries above. I have made them look at the working directory so it should work straight out of the box but It's not too hard to change them if you need to and you can find this in: Project > Properties 

See image here for help:

![The Planet Screenshot](https://i.imgur.com/MkXNa9n.jpg)


# About thePlanet adventure game engine

I have always wanted to create a point and click adventure game ever since the days when I was a teenager and played Monkey Island. ThePlanet is my attempt at creating an adventure game engine in C/C++ and SDL2. This is a work in progress project with many areas for improvement and enhancement. This has been a learning journey for myself in creating games and has been a very tough learning experience but very rewarding at the same time. I do hope that this code will help others like me who have always dreamed about creating a point and click adventure game but just don't know where to start (Getting a sprite to appear on the screen). Starting out programming is a daunting task for any beginner and it seems like a mountain to climb. When starting out creating a game, often people will think that they can make a AAA title, but soon they come to realise that it's really difficult and that's when people give up. But don't! You need to start small and build upon that. I hope this might help others get started and create their own "Better" versions of this engine. I am looking forward to people contributing improvements!

![The Planet Screenshot](https://i.imgur.com/Ym5MogO.jpg)

![The Planet Screenshot](https://i.imgur.com/Ibo1j9c.jpg)

![The Planet Screenshot](https://i.imgur.com/9uA8gGT.jpg)

![The Planet Screenshot](https://i.imgur.com/ehBZHPF.jpg)

The most challenging part of programming in C/C++ and SDL2 is from my point of view (Memory management). I have spent many hours trying to figure out why my RAM suddenly shoots up and how to effectively deal with textures properly to prevent memory leaks. In its current form I think that it is fairly stable and I have managed to overcome the memory leaks to the best of my knowledge.

This project was created in Visual Studio 2019.

Images used in making the scenes were to the best of my knowledge all from google images free to use searches. I actually drew the sprite myself using a mouse, don't laugh! If there are any artists out there, please feel free to make a better character for my game!

# Currently known problems

Occasionally the sprite appears in the text area ( I THINK THIS IS NOW SOLVED!)

Keeping text on the screen long enough for the player to see it. (MOSTLY SOLVED)

Occasional sprite flickering (SOLVED)

# Things you should know

1. The resolution for this game is set to 1024x768 (windowed) however you can stretch the screen by uncommenting the code that does this. However, if you change the resolution to something like 1080p, you will need to update all the coordinates of objects and menu interactions. If you are a mathematician, you could probably do something with this to scale the game and objects using maths to do so. I am planning to look at this myself further down the line.

# Coming soon

Framerate option

