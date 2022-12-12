/**
 * @file main.c
 * @author Jose Luis Cruz (j0z3ph@gmail.com)
 * @brief Simple SDL sample. 
 * 1. Render texture and
 * 2. Handle keyboard and mouse events and 
 * 3. Perform basic texture motion.
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright MIT
 * 
 */

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

#define true 1
#define false 0

int main()
{
    int step = 10; // Pixels that an image moves
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL
    IMG_Init(IMG_INIT_PNG); // Initialize IMG
    SDL_Rect r, rMouse; // Mushroom and Shoot positions
    SDL_Event event; // For handling events
    int running = true; // Flag for main loop
    
    
    // Creates new SDL window
    SDL_Window *gWindow = SDL_CreateWindow("Hello SDL", 0, 0,
                                           SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // Creates the render context of the window
    SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); // Sets white background color

    SDL_Texture *gTexture = NULL; // Mushroom texture
    SDL_Texture *gTextureShoot = NULL; // Shoot texture

    SDL_Surface *img = IMG_Load("Hongo.png"); // Loads PNG file

    gTexture = SDL_CreateTextureFromSurface(gRenderer, img); // Creates mushroom texture from file
    SDL_FreeSurface(img); // Release surface

    img = IMG_Load("shoot.png"); // Loads PNG file
    gTextureShoot = SDL_CreateTextureFromSurface(gRenderer, img); // Creates shoot texture from file
    SDL_FreeSurface(img); // Release surface
    
    // Sets mushroom texture initial position
    // and dimensions
    r.x = 0;
    r.y = 0;
    r.h = 100;
    r.w = 100;

    // Sets shoot texture initial position
    // and dimensions
    rMouse.x = 0;
    rMouse.y = 0;
    rMouse.h = 50;
    rMouse.w = 50;

    // Main loop
    while (running)
    {
        // If an event occurs
        while (SDL_PollEvent(&event))
        {
            // If user requests to close main window
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            // If a key was pressed
            if (event.type == SDL_KEYDOWN /*&& event.key.repeat == 0*/)
            {
                // Adjust the mushroom's location
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    r.y -= step; // UP
                    break;
                case SDLK_DOWN: // DOWN
                    r.y += step;
                    break;
                case SDLK_LEFT: // LEFT
                    r.x -= step;
                    break;
                case SDLK_RIGHT: // RIGHT
                    r.x += step;
                    break;
                }
            }

            // If mouse event happened
            if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
            {
                // Adjust the shoot or mushroom location
                switch (event.type)
                {
                case SDL_MOUSEMOTION:
                    // Get mouse position
                    SDL_GetMouseState(&rMouse.x, &rMouse.y);
                    // Adjust to center
                    rMouse.x = rMouse.x - (rMouse.w / 2);
                    rMouse.y = rMouse.y - (rMouse.h / 2);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Get mouse position
                    SDL_GetMouseState(&r.x, &r.y);
                    r.x = r.x - (r.w / 2);
                    r.y = r.y - (r.h / 2);
                    break;
                case SDL_MOUSEBUTTONUP:
                    break;
                }
            }

            // If the mushroom went too far to the left
            if (r.x < 0) r.x += step;
            
            // If the mushroom went too far to the right
            if ((r.x + r.w) > SCREEN_WIDTH) r.x -= step;
            
            // If the mushroom went too far up
            if (r.y < 0) r.y += step;
            
            // If the mushroom went too far down
            if ((r.y + r.h) > SCREEN_HEIGHT) r.y -= step;
            
        }

        // Clear screen
        SDL_RenderClear(gRenderer);
        // Render textures to screen
        SDL_RenderCopy(gRenderer, gTexture, NULL, &r);
        SDL_RenderCopy(gRenderer, gTextureShoot, NULL, &rMouse);

        // Update screen
        SDL_RenderPresent(gRenderer);

        // SDL_Delay(32);
    }

    // Destroy textures
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;
    SDL_DestroyTexture(gTextureShoot);
    gTexture = NULL;


    // Destroy render and window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    return 0;
}
