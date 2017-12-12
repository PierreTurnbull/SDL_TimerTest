# SDL2 Speed Test

SDL2 Speed Test is a small project of mine meant to ensure that the SDL2 programs I intend to make have an optimal speed rate.
*I am currently learning to use this library, the following results are the result of my experience and readings, nothing more.*

## TEST 1
### Testing a simple renderer flipping

The following test respected an average 15ms per frame:
- nb = 75

## TEST 2
### Testing a renderer color filling

The following test respected an average 15ms per frame:
- nb = 750

## TEST 3
### Testing a rectangle drawing

The following test respected an average 15ms per frame:
- nb = 1, k = 30

## TEST 4
### Testing image copying directly on the renderer

The following tests respected an average 15ms per frame:
(width * height * operations/frame)
- 10 * 10 * 40000
- 600 * 480 * 100
- 1920 * 1080 * 20

## TEST 5
### Testing image copying on a texture, then the texture is copied on the renderer

The following tests respected an average 15ms per frame:
- nb = 10, k = 1
  600 * 480 * 10 * 1 = 2880000px in 10 images rendered per "frame" (or per 10 frames, but each 15ms)
- nb = 1, k = 150
  600 * 480 * 1 * 150 = 43200000px in 1 image rendered per frame
- nb = 1, k = 150
  10 * 10 * 1 * 40000 = 4000000px in 1 image rendered per frame

## CONCLUSION

No conclusion will be given as for the speed of each function, since it is too much variable, probably due to hardware and software reasons, the context in which it is used, and other reasons.
When several textures must be copied on the renderer, all these textures should be first copied on a single texture. This single texture will then be copied on the renderer (See test 4 - 5).
