# Panels AB

Panels AB is a proof of concept and starting point for AB testing using panels and panelizer. It is not recommended for production usage at this point. Eventually it might make a nice D.o project!

With PAB you can

    1. Randomly display various page manager variants with a Randomize selection rule.
    2. Randomly display enabled panels for a given panelized entity when that entity has enabled panels choice.
    
Eventually could abstract the above out to provide more than just randomization display logic aka geolocation and things like that.

## Usage

### Page Manager

To see an example of page manager AB functionality you can go to admin/structure/pages and check out the AB Page Manager Test example.
All the magic happens with page variants and selection rules.

### Panelizer

Panelizer is a little more complicated. To start you need to go to the panelizer config page over at admin/config/content/panelizer
and allow panel choice for the entity bundle you want to AB test. This only works for the full page override at this point.

Once you have done this go to the full page override panelizer settings for your entity bundle and add another panelizer
default to the list. You can add as many as you want but usually just two is sufficient.

When you are happy with the panelizer defaults you have created you now need to tell Panelizer AB to do its thing. 
There are settings called "Panelizer AB" in the "Content Authoring" section of config aka admin/config/content/panels_ab. Check the 
entity bundle you want to AB test and save the form.

What this will do currently is use a random panelizer default from the list of panelizer defaults you built above.

### Caveats

This is a prototype and starting point. Considerations have not yet been made for tracking or performance. 

-------------------------------------------------------------------------------------
(C) 2015 Kalamuna and friends


