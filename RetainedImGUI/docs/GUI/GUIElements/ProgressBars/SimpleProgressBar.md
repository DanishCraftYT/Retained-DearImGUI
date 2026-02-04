# enum ProgressDirection
determines if the Progress Bar should go backwards or forwards.<br>

### values:
* BACKWARD = -1 - makes the Progress Bar go backwards.<br>
* FORWARD = 1 - makes the Progress Bar go forwards.<br>

# class SimpleProgressBar : public GUIElement
handles Simple Progress Bars (this Progress Bar will handle the progression of the Progress Bar for you).<br>

## public SimpleProgressBar(std::string name, float minProgress, float maxProgress, float progressAmount, ProgressDirection direction, ImVec2 size)
constructor for the Simple Progress Bar.<br>

### params:
* std::string name - the name of the Progress Bar.<br>
* float minProgress - the minimum progress of the Progress Bar.<br>
* float maxProgress - the maximum progress of the Progress Bar.<br>
* float progressAmount - the amount of progress that the Progress Bar should progress everytime it's rendered.<br>
* ProgressDirection direction - determines if the Progress Bar goes backwards or forwards.<br>
* ImVec2 size - the size of the Progress Bar.<br>

## public void render() override
renders the Progress Bar.<br>

## public float getProgress()
get's the current progress of the Progress Bar.<br>

### returns:
* the current progress of the Progress Bar.<br>

## public bool hasFinished()
determines if the Progress has finished (reached 100% or 0% depending on the Progress Direction).<br>

### returns:
* true if the Progress Bar has reached 100% or 0% depending on the Progress Direction.<br>
* false if the Progress Bar hasn't finished.<br>

## protected float minProgress
contains the minimum progress of the Progress Bar.<br>

## protected float maxProgress
contains the maximum progress of the Progress Bar.<br>

## protected float progressAmount
contains the amount of progress the Progress Bar should progress everytime it's rendered.<br>

## protected float progress
contains the current progress of the Progress Bar.<br>

## protected ProgressDirection direction
determines if the Progress Bar goes backwards or forwards.<br>

## protected ImVec2 size
contains the size of the Progress Bar.<br>
