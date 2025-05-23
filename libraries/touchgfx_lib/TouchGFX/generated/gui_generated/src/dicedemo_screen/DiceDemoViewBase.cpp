/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/dicedemo_screen/DiceDemoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

DiceDemoViewBase::DiceDemoViewBase() :
    scaleSliderNewScaleValueCallback(this, &DiceDemoViewBase::scaleSliderNewScaleValueCallbackHandler),
    animationsAnimationButtonPressedCallback(this, &DiceDemoViewBase::animationsAnimationButtonPressedCallbackHandler),
    cubeLeftRightButtonsLeftPressedCallback(this, &DiceDemoViewBase::cubeLeftRightButtonsLeftPressedCallbackHandler),
    cubeLeftRightButtonsRightPressedCallback(this, &DiceDemoViewBase::cubeLeftRightButtonsRightPressedCallbackHandler),
    cubeUpDownButtonsUpPressedCallback(this, &DiceDemoViewBase::cubeUpDownButtonsUpPressedCallbackHandler),
    cubeUpDownButtonsDownPressedCallback(this, &DiceDemoViewBase::cubeUpDownButtonsDownPressedCallbackHandler),
    advanceDiceExitAnimationEndedCallback(this, &DiceDemoViewBase::advanceDiceExitAnimationEndedCallbackHandler),
    advanceDiceEnterAnimationEndedCallback(this, &DiceDemoViewBase::advanceDiceEnterAnimationEndedCallbackHandler),
    advanceDiceAnimationDoneCallback(this, &DiceDemoViewBase::advanceDiceAnimationDoneCallbackHandler),
    simpleDiceAnimationDoneCallback(this, &DiceDemoViewBase::simpleDiceAnimationDoneCallbackHandler),
    topbarBackButtonIsPressedCallback(this, &DiceDemoViewBase::topbarBackButtonIsPressedCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backgroundImage.setXY(0, 0);
    backgroundImage.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_WITH_SPARKLES_ID));
    add(backgroundImage);

    topbarBackgroundImage.setXY(0, 0);
    topbarBackgroundImage.setBitmap(touchgfx::Bitmap(BITMAP_TOP_BAR_ID));
    add(topbarBackgroundImage);

    cubeLeftRightButtons.setXY(89, 189);
    cubeLeftRightButtons.setLeftPressedCallback(cubeLeftRightButtonsLeftPressedCallback);
    cubeLeftRightButtons.setRightPressedCallback(cubeLeftRightButtonsRightPressedCallback);
    add(cubeLeftRightButtons);

    cubeUpDownButtons.setXY(322, 50);
    cubeUpDownButtons.setUpPressedCallback(cubeUpDownButtonsUpPressedCallback);
    cubeUpDownButtons.setDownPressedCallback(cubeUpDownButtonsDownPressedCallback);
    add(cubeUpDownButtons);

    animations.setXY(25, 135);
    animations.setAnimationButtonPressedCallback(animationsAnimationButtonPressedCallback);
    add(animations);

    scaleSlider.setXY(694, 80);
    scaleSlider.setNewScaleValueCallback(scaleSliderNewScaleValueCallback);
    add(scaleSlider);

    simpleDice.setXY(0, 0);
    simpleDice.setAnimationDoneCallback(simpleDiceAnimationDoneCallback);
    add(simpleDice);

    advanceDice.setXY(0, 0);
    advanceDice.setVisible(false);
    advanceDice.setExitAnimationEndedCallback(advanceDiceExitAnimationEndedCallback);
    advanceDice.setEnterAnimationEndedCallback(advanceDiceEnterAnimationEndedCallback);
    advanceDice.setAnimationDoneCallback(advanceDiceAnimationDoneCallback);
    add(advanceDice);

    topbar.setXY(0, 0);
    topbar.setBackButtonIsPressedCallback(topbarBackButtonIsPressedCallback);
    add(topbar);
}

DiceDemoViewBase::~DiceDemoViewBase()
{

}

void DiceDemoViewBase::setupScreen()
{
    cubeLeftRightButtons.initialize();
    cubeUpDownButtons.initialize();
    animations.initialize();
    scaleSlider.initialize();
    simpleDice.initialize();
    advanceDice.initialize();
    topbar.initialize();
}

void DiceDemoViewBase::scaleSliderNewScaleValueCallbackHandler(float value)
{
    //ScaleSliderChanged
    //When scaleSlider newScaleValue call scaleSliderChanged on DiceDemo
    //Call scaleSliderChanged
    scaleSliderChanged(value);
}

void DiceDemoViewBase::animationsAnimationButtonPressedCallbackHandler(bool value)
{
    //AnimationComplexityChanged
    //When animations animationButtonPressed call animationComplexTionChanged on DiceDemo
    //Call animationComplexTionChanged
    animationComplexTionChanged(value);
}

void DiceDemoViewBase::cubeLeftRightButtonsLeftPressedCallbackHandler()
{
    //LeftPressed
    //When cubeLeftRightButtons leftPressed call leftPressed on DiceDemo
    //Call leftPressed
    leftPressed();
}

void DiceDemoViewBase::cubeLeftRightButtonsRightPressedCallbackHandler()
{
    //RightPressed
    //When cubeLeftRightButtons rightPressed call rightPressed on DiceDemo
    //Call rightPressed
    rightPressed();
}

void DiceDemoViewBase::cubeUpDownButtonsUpPressedCallbackHandler()
{
    //UpPressed
    //When cubeUpDownButtons upPressed call upPressed on DiceDemo
    //Call upPressed
    upPressed();
}

void DiceDemoViewBase::cubeUpDownButtonsDownPressedCallbackHandler()
{
    //DownPressed
    //When cubeUpDownButtons downPressed call downPressed on DiceDemo
    //Call downPressed
    downPressed();
}

void DiceDemoViewBase::advanceDiceExitAnimationEndedCallbackHandler()
{
    //ExitCubeAnimationEnded
    //When advanceDice exitAnimationEnded call exitCubeAnimationEnded on DiceDemo
    //Call exitCubeAnimationEnded
    exitCubeAnimationEnded();
}

void DiceDemoViewBase::advanceDiceEnterAnimationEndedCallbackHandler()
{
    //EnterCubeAnimationEnded
    //When advanceDice enterAnimationEnded call enterCubeAnimationEnded on DiceDemo
    //Call enterCubeAnimationEnded
    enterCubeAnimationEnded();
}

void DiceDemoViewBase::advanceDiceAnimationDoneCallbackHandler()
{
    //AdvanceAnimationDone
    //When advanceDice animationDone call animationDone on DiceDemo
    //Call animationDone
    animationDone();
}

void DiceDemoViewBase::simpleDiceAnimationDoneCallbackHandler()
{
    //SimpleAnimationDone
    //When simpleDice animationDone call animationDone on DiceDemo
    //Call animationDone
    animationDone();
}

void DiceDemoViewBase::topbarBackButtonIsPressedCallbackHandler()
{
    //GoBackToMenu
    //When topbar backButtonIsPressed change screen to Menu
    //Go to Menu with screen transition towards South
    application().gotoMenuScreenWipeTransitionSouth();
}
