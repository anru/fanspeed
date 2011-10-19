Arduino library for reading fan speed in RPM from any digital port
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

General methods
"""""""""""""""

FanSpeed or FanSpeedInt(int pin, bool useInternalResistor = true) 
    :pin: if pin is 13 useInternalResistor has no sense, use external resistor in this case.

FanSpeed::getPulseCounter()
    returns the pulse counter

FanSpeed::reset()
    Resets the pulse counter

FanSpeed::process()
    Handling counter, use depends on the type of class, in the case of pin that supports interrupt (class FanSpeedInt), this function must be called in the callback function, otherwise if you use an ordinary digital port, the function must be called a global handler loop, as often as possible.

Examples
""""""""

Examples located in examples sub directory

Scheme
""""""

.. image:: https://github.com/anru/fanspeed/raw/master/examples/shema.jpg
