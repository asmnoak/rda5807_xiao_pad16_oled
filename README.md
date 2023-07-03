<p><H3>16KEY PADを使用した RDA5807 FM DSPラジオ</H3></p>
<p>
RDA5807FPは、RDAマイクロ製のFM対応のDSPラジオICである。SOP16ピンのパッケージで、変換基板にハンダ付けして使用した（パッケージタイプ（副番）が色々あるので注意）。<br><a href="https://www.aitendo.com/product/4797">安価（データシートの参照リンクあり）</a>に購入でき、使用部品が少なくて済むので使い易い。<br>
I2Cインターフェースでコントロールするので、Arduinoとの組み合わせが可能である。<br>
ここでは、Seeeduino XIAOと組み合わせる。RDA5807FPは電圧3.3Vで動作し、必要な電流は20mA程度なので、XIAO（3V3端子）から供給できる。<br>
使用したRDA5807用のライブラリは、<a href="https://github.com/pu2clr/RDA5807">こちら（pu2clr at GitHub）</a>にある。<br>
基本的な使い方は、<a href="https://qiita.com/nanase/items/b9efc547d395d2d7cbc0">こちら（Qiita）</a>を参考にすると良い。<br>
</p>
<p>
選局やボリュームの変更には、<a href="https://www.aitendo.com/product/7297">4x4のKeypad</a>を使用する。XIAOとは<a href="https://www.aitendo.com/product/9891">MCP23107というIC（基板）</a>を経由して、I2Cインターフェースで接続する。<br>
MCP23017をサポートする<a title="Keypadライブラリ" href="https://github.com/joeyoung/arduino_keypads">Keypad_MC17.hライブラリ</a>を利用した。<br>
このライブラリは標準のKeypad.hライブラリを拡張している。
</p>

<p><strong>機能</strong><br>
16個のタクトスイッチの内、２個はボリュームの増減、１個は、低音のブースト切替に使用、残りの13個は選局（プログラミングが必要）に使用できる。<br>OLED（横長の物を使用）には、選局した周波数、ボリュームの数値、信号強度（RSSI）を表示している。
受信周波数の範囲は、76－108MHz（に設定した）で、ワイドFM対応である。<br>出力はオーディオジャック経由で小口径のスピーカー（ステレオ）を接続する。
</p>
<p><strong>H/W構成</strong><br>
 ・Seeeduino XIAO - コントローラ<br>
 ・SSD1306 128x32 OLED表示装置<br>
 ・4x4のKeypad<br>
 ・Xtal発振器（32768Hz）、コンデンサ類<br>
 ・MCP23107基板<br>
 ・I2C接続&nbsp; RDA5807FP、表示装置、MCP23107（マルチドロップで接続）<br>
   &nbsp;&nbsp;&nbsp; ３つ同時に接続した時点で応答が無くなったので、SCKとSDAに5.6KΩのプルアップ抵抗を接続してある<br>
</p>
<p>
<img src="https://github.com/asmnoak/rda5807_xiao_pad16_oled/blob/main/RDA5807_XIAO_PAD_1.JPG" width="360" height="440"><br>
汎用基板に実装。手前がXIAO、奥がRDA5807。アクリルケースの上面にKeypadを配置。
</p>
<p><strong>接続</strong><br>
各コンポーネントの接続は以下の通り。<br>
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
I2Cのアドレス
<table> 
<tr>
<td>RDA5807FP</td><td>0x10&nbsp;or&nbsp;0x11&nbsp;ライブラリで既定</td>
</tr>
<tr>
<td>OLED</td><td>0x3C&nbsp;既定</td>
</tr>
<tr>
<td>MCP23107</td><td>0x20&nbsp;基板のハンダ付け（ブリッジジャンパー）で設定</td>
</tr>
</table>
</p>
<p><strong>インストール</strong><br>
<ol>
<li>コードを、ZIP形式でダウンロード</li>
<li>ArduinoIDEにおいて、ライブラリマネージャから以下を検索してインストールする</li>
 <ul>
  <li>Adafruit_BusIO</li>
  <li>Adafruit_GFX</li>
  <li>Adafruit_SSD1306</li>
 </ul>
<li>追加のライブラリ（文中のリンクより）を、ZIP形式でダウンロード、ライブラリマネージャからインストールする</li>
 <ul>
  <li>RDA5807</li>
  <li>MCP23107</li>
 </ul>
<li>ArduinoIDEからrda5807_xiao_pad16_oled.inoを開く</li>
<li>「検証・コンパイル」に成功したら、一旦、「名前を付けて保存」を行う</li>
</ol>
</p>
<p><strong>若干の解説</strong><br>
・回路図はデータシートを参照のこと。LOUT、ROUTのコンデンサは100－200μF程度を接続すると音質が良くなる。なお、回路図にあるインダクタンス系の部品は無くても動作する。<br>
・stnFreq[]に受信する放送局の周波数を指定する。例えば80.4MHzの場合、8040と指定する。なお、stnName[]はコメントであり、表示には使っていない。<br>
・MCP23107の基板とKeypad間は8本の線で接続する必要がある。MCP23107は電圧レベルを合わせるため、3.3Vで動作させている。<br>
<p>
<img src="https://github.com/asmnoak/rda5807_xiao_pad16_oled/blob/master/RDA5807_XIAO_PAD_2.jpg" width="360" height="480"><br>
</p>
</p>
<p><strong>注意事項</strong><br>
・利用の際は、自己責任でお楽しみください。<br>
</p>
