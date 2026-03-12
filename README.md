# DP-Week2-5224600081-Mochamad-Fahmi-Habib-Iqtishom

1. Apa struktur invariant dalam program Anda?

Struktur invariant dalam program ini adalah urutan fase run yang dikontrol oleh RunSession. Fase tersebut selalu berjalan dalam urutan yang sama, yaitu: generate input, menghitung base score, menghitung reward, update cash, fase shop, dan pindah ke ronde berikutnya. Urutan ini membentuk alur utama sistem permainan. Jika urutan ini diubah, maka logika run dalam game dapat menjadi tidak konsisten karena setiap fase bergantung pada hasil dari fase sebelumnya. Sebagai contoh, perhitungan reward membutuhkan nilai base score, dan fase shop membutuhkan nilai uang yang sudah diperbarui.


2. Bagian mana yang bersifat mutable?

Bagian yang bersifat mutable dalam sistem ini meliputi input generation, scoring rule, reward rule, dan shop behavior. Komponen-komponen tersebut dapat diubah tanpa mempengaruhi struktur utama loop. Misalnya, input generator dapat diganti dari nilai tetap menjadi nilai acak. Selain itu, rumus reward juga dapat diubah dari reward = baseScore menjadi reward = baseScore + 2. Perubahan tersebut hanya mempengaruhi perilaku permainan, tetapi tidak mengubah struktur fase yang dikontrol oleh RunSession.


3. Ketika Anda mengganti InputGenerator, mengapa RunSession tidak perlu diubah?

RunSession bergantung pada interface IInputGenerator, bukan pada implementasi spesifik dari generator input. Karena adanya abstraksi ini, kita dapat mengganti FixedInputGenerator dengan RandomInputGenerator tanpa perlu mengubah kode pada RunSession. RunSession hanya memanggil fungsi GenerateInput() tanpa mengetahui bagaimana nilai tersebut dihasilkan.


4. Apa yang akan terjadi jika logika scoring ditempatkan langsung di dalam RunSession?

Jika logika scoring ditempatkan langsung di dalam RunSession, maka kelas tersebut akan menjadi terikat langsung dengan aturan gameplay. Setiap kali aturan scoring berubah, kita harus memodifikasi RunSession. Hal ini melanggar prinsip Separation of Responsibilities, yaitu prinsip yang menyatakan bahwa setiap bagian program memiliki tugasnya masing-masing dan tidak mencampur tanggung jawab dengan bagian lain. Akibatnya, sistem dapat menjadi lebih sulit untuk diperluas maupun untuk diuji. Dengan memisahkan logika scoring ke dalam kelas tersendiri, struktur invariant dari sistem tetap terjaga dan perubahan aturan dapat dilakukan dengan lebih fleksibel.