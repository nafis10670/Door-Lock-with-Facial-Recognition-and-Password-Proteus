<h1>Door Lock with Facial Recognition and Password using Proteus</h1>
<p>A door lock system made with Arduino in Proteus software that uses both facial recognition and password as authentication methods.</p>

<h2>User Manual</h2>
<ol>
  <li>Download the two Python Scripts (<i>face_trainer.py, face_recogniser1.py</i>), the Proteus Project (<i>Demo.pdsprj</i>), the Arduino code (<i>facial_servo_controller.ino</i>) and all other files from <a href ="https://github.com/nafis10670/Door-Lock-with-Facial-Recognition-and-Password-Proteus">Github</a>.</li>
  <li>Since we are doing everything virtually, we will need virtual serial ports. Using any software that will let you create virtual serial ports, create two virtual serial ports at <b>“COM1”</b> and <b>“COM2”</b>. Our arduino will be connected to <b>“COM2”</b>. For our project, we used <i>“Virtual Serial Port Driver”</i> software to simulate the serial ports.</li>
  <li>Run the Proteus Project (<i>Demo.pdsprj</i>).</li>
  <li>In the lower left corner, press the Play button. The system should be powered up and the LCD Screen should show <i>“Enter code or face recognition”</i>.</li>
  <li>Enter the code “0123” to rotate the Servo Motor with “Access Granted” being displayed on the LCD Screen. Entering the incorrect code 3 times will result in the red LED bulb  blinking three times.</li>
  <li>If you want to train your face, upload folders in the <i>“image_data”</i> folder with the images in the folder in either <i>.png</i> or <i>.jpg</i> format. The name of the folder will be the name that our Python script will use as the name of the person. Run the <i>“face_traine.py”</i> Python script to train the system.</li>
  <li>With the Proteus project still in debugging mode, run the <i>“face_recogniser1.py”</i> Python script. Your webcam should open.</li>
  <li>If your face matches one of the previously trained faces, you will see the Servo Motor rotating and the LCD Screen displaying “Access Granted”.</li>
</ol>

<h2>Meet the team</h2>
<ul>
	<li>
		<a href="https://github.com/nafis10670">Nafis Saami Azad</a>
	</li>
	<li>
		<a href="https://github.com/Muhai10">Al Muhaimin</a>
	</li>
	<li>
		<a href="https://github.com/Nowshad66">Nowshadul Islam Nishad</a>
	</li>
</ul>
