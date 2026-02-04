# class ProgressBar : public SimpleProgressBar
handles Progress Bars which needs to be manually updated without the need to update the progress amount.<br>

## public ProgressBar(std::string name, float minProgress, float maxProgress, float progressAmount, ProgressDirection direction, ImVec2 size)
constructor for the ProgressBar class.<br>

### params:
* std::string name - the name of the Progress Bar.<br>
* float minProgress - the minimum progress of the Progress Bar.<br>
* float maxProgress - the maximum progress of the Progress Bar.<br>
* float progressAmount - the amount of progress that the Progress Bar should progress everytime it's rendered.<br>
* ProgressDirection direction - determines if the Progress Bar goes backwards or forwards.<br>
* ImVec2 size - the size of the Progress Bar.<br>

## public void render() override
renders the Progress Bar.<br>

## public void update(bool useDeltaTime=false)
updates the progression of the Progress Bar.<br>

### params:
* bool useDeltaTime=false - determines if it should use delta time to update the Progress Bar (it's recommended if your gonna update it in the render loop).<br>
