rock_find_qt4(OPTIONAL)
rock_find_qt5(OPTIONAL)

if(ROCK_QT_VERSION_4)
    rock_vizkit_plugin(trajectory_follower-viz
        SubTrajectoryVisualization.cpp
        DEPS trajectory_follower
        DEPS_PKGCONFIG osgViz
        DEPS_CMAKE Qt4
        MOC SubTrajectoryVisualization.hpp
        HEADERS SubTrajectoryVisualization.hpp)
endif(ROCK_QT_VERSION_4)

if(ROCK_QT_VERSION_5)
    rock_vizkit_plugin_qt5(trajectory_follower-viz-qt5
        SubTrajectoryVisualization.cpp
        DEPS trajectory_follower
        DEPS_PKGCONFIG osgViz
        MOC5 SubTrajectoryVisualization.hpp
        HEADERS SubTrajectoryVisualization.hpp)
endif(ROCK_QT_VERSION_5)
