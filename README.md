<p><H3>16KEY PAD���g�p���� RDA5807 FM DSP���W�I</H3></p>
<p>
RDA5807FP�́ARDA�}�C�N������FM�Ή���DSP���W�IIC�ł���BSOP16�s���̃p�b�P�[�W�ŁA�ϊ���Ƀn���_�t�����Ďg�p�����i�p�b�P�[�W�^�C�v�i���ԁj���F�X����̂Œ��Ӂj�B<br><a href="https://www.aitendo.com/product/4797">�����i�f�[�^�V�[�g�̎Q�ƃ����N����j</a>�ɍw���ł��A�g�p���i�����Ȃ��čςނ̂Ŏg���Ղ��B<br>
I2C�C���^�[�t�F�[�X�ŃR���g���[������̂ŁAArduino�Ƃ̑g�ݍ��킹���\�ł���B<br>
�����ł́ASeeeduino XIAO�Ƒg�ݍ��킹��BRDA5807FP�͓d��3.3V�œ��삵�A�K�v�ȓd����20mA���x�Ȃ̂ŁAXIAO�i3V3�[�q�j���狟���ł���B<br>
�g�p����RDA5807�p�̃��C�u�����́A<a href="https://github.com/pu2clr/RDA5807">������ipu2clr at GitHub�j</a>�ɂ���B<br>
��{�I�Ȏg�����́A<a href="https://qiita.com/nanase/items/b9efc547d395d2d7cbc0">������iQiita�j</a>���Q�l�ɂ���Ɨǂ��B<br>
</p>
<p>
�I�ǂ�{�����[���̕ύX�ɂ́A<a href="https://www.aitendo.com/product/7297">4x4��Keypad</a>���g�p����BXIAO�Ƃ�<a href="https://www.aitendo.com/product/9891">MCP23107�Ƃ���IC�i��j</a>���o�R���āAI2C�C���^�[�t�F�[�X�Őڑ�����B<br>
MCP23017���T�|�[�g����<a title="Keypad���C�u����" href="https://github.com/joeyoung/arduino_keypads">Keypad_MC17.h���C�u����</a>�𗘗p�����B<br>
���̃��C�u�����͕W����Keypad.h���C�u�������g�����Ă���B
</p>

<p><strong>�@�\</strong><br>
16�̃^�N�g�X�C�b�`�̓��A�Q�̓{�����[���̑����A�P�́A�ቹ�̃u�[�X�g�ؑւɎg�p�A�c���13�͑I�ǁi�v���O���~���O���K�v�j�Ɏg�p�ł���B<br>OLED�i�����̕����g�p�j�ɂ́A�I�ǂ������g���A�{�����[���̐��l�A�M�����x�iRSSI�j��\�����Ă���B
��M���g���͈̔͂́A76�|108MHz�i�ɐݒ肵���j�ŁA���C�hFM�Ή��ł���B<br>�o�͂̓I�[�f�B�I�W���b�N�o�R�ŏ����a�̃X�s�[�J�[�i�X�e���I�j��ڑ�����B
</p>
<p><strong>H/W�\��</strong><br>
 �ESeeeduino XIAO - �R���g���[��<br>
 �ESSD1306 128x32 OLED�\�����u<br>
 �E4x4��Keypad<br>
 �EXtal���U��i32768Hz�j�A�R���f���T��<br>
 �EMCP23107���<br>
 �EI2C�ڑ�&nbsp; RDA5807FP�A�\�����u�AMCP23107�i�}���`�h���b�v�Őڑ��j<br>
   &nbsp;&nbsp;&nbsp; �R�����ɐڑ��������_�ŉ����������Ȃ����̂ŁASCK��SDA��5.6K���̃v���A�b�v��R��ڑ����Ă���<br>
</p>
<p>
<img src="./RDA5807_XIAO_PAD_1.jpg" width="360" height="440"><br>
�ėp��Ɏ����B��O��XIAO�A����RDA5807�B�A�N�����P�[�X�̏�ʂ�Keypad��z�u�B
</p>
<p><strong>�ڑ�</strong><br>
�e�R���|�[�l���g�̐ڑ��͈ȉ��̒ʂ�B<br>
<p>
<table> 
<tr>
<td>I2C&nbsp;</td><td>XIAO</td>
</tr>
<tr>
<td>SCK</td><td>D5</td>
<tr>
<tr>
<td>SDA</td><td>D4</td>
<tr>
</table>
</p>
</p>
<p>
I2C�̃A�h���X
<table> 
<tr>
<td>RDA5807FP</td><td>0x10&nbsp;or&nbsp;0x11&nbsp;���C�u�����Ŋ���</td>
</tr>
<tr>
<td>OLED</td><td>0x3C&nbsp;����</td>
</tr>
<tr>
<td>MCP23107</td><td>0x20&nbsp;��̃n���_�t���i�u���b�W�W�����p�[�j�Őݒ�</td>
</tr>
</table>
</p>
<p><strong>�C���X�g�[��</strong><br>
<ol>
<li>�R�[�h���AZIP�`���Ń_�E�����[�h</li>
<li>ArduinoIDE�ɂ����āA���C�u�����}�l�[�W������ȉ����������ăC���X�g�[������</li>
 <ul>
  <li>Adafruit_BusIO</li>
  <li>Adafruit_GFX</li>
  <li>Adafruit_SSD1306</li>
 </ul>
<li>�ǉ��̃��C�u�����i�����̃����N���j���AZIP�`���Ń_�E�����[�h�A���C�u�����}�l�[�W������C���X�g�[������</li>
 <ul>
  <li>RDA5807</li>
  <li>MCP23107</li>
 </ul>
<li>ArduinoIDE����rda5807_xiao_pad16_oled.ino���J��</li>
<li>�u���؁E�R���p�C���v�ɐ���������A��U�A�u���O��t���ĕۑ��v���s��</li>
</ol>
</p>
<p><strong>�኱�̉��</strong><br>
�E��H�}�̓f�[�^�V�[�g���Q�Ƃ̂��ƁBLOUT�AROUT�̃R���f���T��100�|200��F���x��ڑ�����Ɖ������ǂ��Ȃ�B�Ȃ��A��H�}�ɂ���C���_�N�^���X�n�̕��i�͖����Ă����삷��B<br>
�EstnFreq[]�Ɏ�M��������ǂ̎��g�����w�肷��B�Ⴆ��80.4MHz�̏ꍇ�A8040�Ǝw�肷��B�Ȃ��AstnName[]�̓R�����g�ł���A�\���ɂ͎g���Ă��Ȃ��B<br>
�EMCP23107�̊��Keypad�Ԃ�8�{�̐��Őڑ�����K�v������BMCP23107�͓d�����x�������킹�邽�߁A3.3V�œ��삳���Ă���B<br>
<p>
<img src="./RDA5807_XIAO_PAD_2.jpg" width="360" height="480"><br>
</p>
</p>
<p><strong>���ӎ���</strong><br>
�E���p�̍ۂ́A���ȐӔC�ł��y���݂��������B<br>
</p>
