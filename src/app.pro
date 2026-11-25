TEMPLATE = subdirs

SUBDIRS += \
    appcore \
    appgui \
    appthread \


appcore.depends = 
appgui.depends = appcore
appthread.depends = appcore
