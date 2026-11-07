/*
 * File: ToneMatrix.h
 * Names: Srishti Boral, Anika Mukherjee
 * Course: CS 106B
 *
 * Description: This file declares the ToneMatrix class, a grid of lights where
 * each row plays a note. It stores the lights, the instruments for each row,
 * what the last mouse press did, and where the sweep is across the columns.
 */
#pragma once

#include "Demos/Sample.h"
#include "StringInstrument.h"
#include "GUI/SimpleTest.h"

/* Type that maintains a Tone Matrix, reacts to mouse movement,
 * handles graphics, and sends data to the computer speakers.
 */
class ToneMatrix {
public:
    /* Creates a Tone Matrix whose grid is gridSize x gridSize and
     * where each light in the matrix has size lightSize x lightSize.
     * The lightSize parameter just determines the size, in pixels,
     * of each light in the grid.
     */
    ToneMatrix(int gridSize, int lightSize);

    /* Frees all memory allocated by the ToneMatrix type. */
    ~ToneMatrix();

    /* Reacts to the mouse being pressed at a given location.
     * Specifically, this toggles the state of the light under the
     * mouse.
     */
    void mousePressed(int mouseX, int mouseY);

    /* Reacts to the mouse being dragged at a given location (moved
     * while pressed). Specifically, this updates the light under the
     * mouse to match the state of the light where the mouse was
     * first pressed.
     */
    void mouseDragged(int mouseX, int mouseY);

    /* Draws the Tone Matrix to the screen. */
    void draw() const;

    /* Produces the next sound sample from the Tone Matrix. */
    Sample nextSample();

    /* Resizes the underlying grid of lights. New lights default
     * to being turned off; old lights retain their previous
     * values. Old instruments are preserved. The left-to-right
     * scan of the grid resets back to the leftmost column, as if
     * the Tone Matrix was being created anew.
     */
    void resize(int newGridSize);

private:
    int _gridSize;
    int _lightSize;
    bool* _grid = nullptr;
    StringInstrument* _instruments = nullptr;

    /* True if the last mousePressed turned a light on, false if it
     * turned a light off. mouseDragged uses this to know what to do.
     */
    bool _dragTurnsOn = false;

    //The column that gets plucked next.
    int _currentCol = 0;

    /* How many more calls to nextSample until the next column gets plucked.
     * Starts at 0 so the very first call plucks. */
    int _samplesUntilPluck = 0;

    // Returns the index in _grid of the light under the mouse.
    int indexFor(int mouseX, int mouseY) const;

    /* Allow SimpleTest test cases to read private fields. */
    ALLOW_TEST_ACCESS();
};
