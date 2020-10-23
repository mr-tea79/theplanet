# theplanet
An adventure game in C/C++ SDL2 to help people who always dreamed of making a point and click adventure game but don't know where to begin.
This is being developed in my spare time and by no means finished. This is aimed at people who are learning to program and need a template to get started with making a game. Lots of scope for improvement of the code!

If you have enjoyed this and it has helped you get started in C++ and SDL2, please feel free to make a small donation via this link below: 

[Donate Here](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=8TW9LN5YTRBKL)



You are free to use this source code to make improvements, new games, anything! I just ask that you keep my name in the code as a nod of acknowledgement to all the many hours of work making this.

You will need the following libraries which can be downloaded. One is for dealing with images and the other for text.

#SDL_image   (For images)
https://sites.google.com/site/sdlinvc2010/installation/sdl_image

#SDL_ttf    (For text)
https://sites.google.com/site/sdlinvc2010/installation/sdl_ttf

#sqlite3    (For inventory)
https://dcravey.wordpress.com/2011/03/21/using-sqlite-in-a-visual-c-application/

# About thePlanet adventure game engine

I have always wanted to create a point and click adventure game ever since the days when I was a teenager and played Monkey Island. ThePlanet is my attempt at creating an adventure game engine in C++ and SDL2. This is a work in progress project with many areas for improvement and enhancement. This has been a learning journey for myself in creating games in C++ and has been a very tough learning experience but very rewarding at the same time. I do hope that this code will help others like me who have always dreamed about creating a point and click adventure game but just don't know where to start. Starting out programming in C++ is a daunting task for any beginner and it seems like a mountain to climb. I hope this might help others get started and create their own "Better" versions of this engine. I am looking forward to people contributing improvements!

![The Planet Screenshot](https://i.imgur.com/Ym5MogO.jpg)

![The Planet Screenshot](https://i.imgur.com/Ibo1j9c.jpg)
The most challenging part of programming in C++ and SDL2 is from my point of view (Memory management). Many hours I have spent trying to figure out why my RAM suddenly shoots up and how to effectively deal with textures properly to prevent memory leaks. In its current form I think that it is fairly stable and I have managed to overcome the memory leaks to the best of my knowledge.

This project was created in Visual Studio 2019.

Images used in making the scenes were to the best of my knowledge all from google images free to use searches.

# Current known problems that I have yet to overcome

Keeping text on the screen long enough for the player to see it.

Occasional sprite flickering

# Things to be aware of

1. The resolution for this game is set to 1024x768 (windowed) however you can stretch the screen by uncommenting the code that does this. However if you change the resolution to something like 1080p, you will need to update all the coordinates of objects and menu interactions.



