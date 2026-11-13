TEMPLATE = subdirs

SUBDIRS += \
    appcore \
    appgui \


appcore.depends = 
appgui.depends = appcore
