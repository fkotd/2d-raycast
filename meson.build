project('raycast', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

sfml_graphics = dependency('sfml-graphics')
sfml_window = dependency('sfml-window')
sfml_system = dependency('sfml-system')

executable('raycast',
           'segment.cpp',
           'ray.cpp',
					 'obstacle.cpp',
           'main.cpp',
					 dependencies : [sfml_graphics, sfml_window, sfml_system],
           install : true)
