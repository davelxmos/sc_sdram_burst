.. _sdram_demo_Quickstart:

sc_sdram_burst demo : Quick Start Guide
---------------------------------------

This simple demonstration of xTIMEcomposer Studio functionality uses the XA-SK-SDRAM Slice Card together with the xSOFTip module_sdram to demonstrate how the module is used to read and write to the SDRAM.

Hardware Setup
++++++++++++++

The XP-SKC-L2 Slicekit Core board has four slots with edge conectors: ``SQUARE``, ``CIRCLE``,``TRIANGLE`` and ``STAR``. 

To setup up the system:

   #. Connect XA-SK-SDRAM Slice Card to the XP-SKC-L2 Slicekit Core board using the connector marked with the ``STAR``.
   #. Connect the XTAG Adapter to Slicekit Core board, and connect XTAG-2 to the adapter. 
   #. Connect the XTAG-2 to host PC. Note that the USB cable is not provided with the Slicekit starter kit.
   #. Set the ``XMOS LINK`` to ``OFF`` on the XTAG Adapter.
   #. Switch on the power supply to the Slicekit Core board.

.. figure:: images/hardware_setup.jpg
   :width: 400px
   :align: center

   Hardware Setup for SDRAM Demo
   
	
Import and Build the Application
++++++++++++++++++++++++++++++++

   #. Open xTIMEcomposer and check that it is operating in online mode. Open the edit perspective (Window->Open Perspective->XMOS Edit).
   #. Locate the ``'Slicekit SDRAM Demo'`` item in the xSOFTip pane on the bottom left of the window and drag it into the Project Explorer window in the xTIMEcomposer. This will also cause the modules on which this application depends (in this case, module_sdram) to be imported as well. 
   #. Click on the app_sdram_demo item in the Explorer pane then click on the build icon (hammer) in xTIMEcomposer. Check the console window to verify that the application has built successfully.

For help in using xTIMEcomposer, try the xTIMEcomposer tutorial. FIXME add link.

Note that the Developer Column in the xTIMEcomposer on the right hand side of your screen provides information on the xSOFTip components you are using. Select the module_sdram component in the Project Explorer, and you will see its description together with API documentation. Having done this, click the `back` icon until you return to this quickstart guide within the Developer Column.

Run the Application
+++++++++++++++++++

Now that the application has been compiled, the next step is to run it on the Slicekit Core Board using the tools to load the application over JTAG (via the XTAG2 and Xtag Adaptor card) into the xCORE multicore microcontroller.

   #. Click on the ``Run`` icon (the white arrow in the green circle). The debug console window in xTIMEcomposer should then display the message  ``SDRAM demo complete``. This has been generated from the application code via a call to the ``printf()`` function. 
   #. If ``SDRAM demo fail`` is shown then check that the ``XMOS LINK`` is set to ``OFF`` then repeat.
    
Next Steps
++++++++++

Now that the demo has been run you could try:
   #. Adjust the ``BUF_WORDS``. Note, if you try to allocate more than 64KB of internal XCore memory then the demo will not compile as the Xcore wont be able to hold the image.
   #. Change ``sdram_buffer_read(server, bank, row, col, BUF_WORDS, read_buffer);`` to ``sdram_buffer_read(server, bank, row, col+2, BUF_WORDS-1, read_buffer);``. What would you expect to happen?

Look at the Code
................

   #. Examine the application code. In xTIMEcomposer navigate to the ``src`` directory under app_sdram_demo and double click on the ``app_sdram_demo.xc`` file within it. The file will open in the central editor window.
   #. Find the main function and note that it runs the ``application()`` function on a single logical core. 
   #. Find the ``sdram_buffer_write`` function within ``application()``. There are 4 SDRAM I/O commands: ``sdram_buffer_write``, ``sdram_buffer_read``, ``sdram_full_page_write``, ``sdram_full_page_read``. They must all be followed by a ``sdram_wait_until_idle`` before another I/O command may be issued. When the ``sdram_wait_until_idle`` returns then the data is now at it destination. This functionality allows the application to be getting on with something else whilst the SDRAM server is busy with the I/O. 
   #. There is no need to explictly refresh the SDRAM as this is managed by the ``sdram_server``.

Try the Benchmark and Regressession Demo
........................................

After completing this demo there are two more application to try: 
  #. ``app_sdram_benchmark`` benchmarks the performance of the module. It does no correctness testing but instead tests the throughput of the SDRAM server.  
  #. ``app_sdram_regress`` this demo runs a series of regression tests of increasing difficulty, beginning from using a single core for the sdram_server with one core loaded progressing to all cores being loaded to simulate an XCore under full load.  

To try these repeat the procedure in "Import and Build the Application" but with either  ``app_sdram_benchmark`` or ``app_sdram_regress``.
   