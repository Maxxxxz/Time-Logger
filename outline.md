# Outline for Time Logging application

* C++
* WxWidgets
* Default main window features a weekly timesheet
    * User will be able to click to log time to a specific 'task'
    * User will be able to set any location as their main window
* Main window features a top-bar which allows user to navigate to self-made 'tasks'
* 'Tasks' window features an add 'task' button, allowing the user to add a 'task'
    * A 'task' will have a name, description, category, estimated time, and starting time (initial time)
    * The 'task' will have the user's local timestamp as a creation date
* 'Tasks' window features the list of all currently active 'tasks' with a summary of time and category.
    * A user will be able to select a specific 'task' and edit all fields
    * A user will be able to select a specific 'task' and log time (adds time to the initial time)
* File options will include 'generate backup file' which exports a backup file of all times user has ever entered
    * This might need to be made carefully. Multiple years of use could cause issues with filesize. How to solve?
        * Keep 1 year worth of times before squashing into 1 year file?

* How will the times and tasks be saved?
    * JSON or YAML?