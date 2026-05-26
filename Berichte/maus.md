# Arbeitsbericht vom 25.02.2026

- Name: Felix Resch
- Klasse: 2AHITS
- Gruppe 2
- Fach: ITSI Übungen
- Thema: Tools 2 (Teil 2)

## Übung 3.4 (find)

### Setze das Arbeitsverzeichnis auf ~/workspace und führe aus:

find -name "*.md"

### Ausgabe
```sh
~/workspace$ find -name "*.md*"
./README.md
./berichte/250917.md
./berichte/251001.md
./berichte/251015.md
./berichte/251105.md
./berichte/251119.md
./berichte/251217.md
./berichte/260121.md
./berichte/260225.md
```
Recherchiere zum find Befehl und löse folgende Aufgabenstellungen:

### Suche, von ~ (Homeverzeichnis) aus, nach

dem Directory mit dem Namen profiles
```sh
~$ find -name "profiles"
./.local/state/nix/profiles
```
dem File mit dem Namen .latest.json
```sh
~$ find -name ".latest.json"
./workspace/.local/state/replit/agent/.latest.json
```
allen Files die auf .json enden
```sh
~$ find -name "*.json"
./workspace/.cache/replit/env/latest.json
./workspace/.cache/replit/nix/dotreplitenv.json
./workspace/.cache/replit/toolchain.json
./workspace/.local/state/replit/agent/.latest.json
./workspace/.upm/store.json
~$ 
```
allen Directories
```sh
~$ find -type d
.
./.nix-defexpr
./.cache
./.cache/nix
./.cache/snowflake
./.local
./.local/state
./.local/state/nix
./.local/state/nix/profiles
./workspace
./workspace/.cache
./workspace/.cache/replit
./workspace/.cache/replit/modules
........
```
allen Markdown Files die in den letzten 4 Wochen geändert wurden
```sh
~$ find -mtime -28 -name "*.md"
./workspace/berichte/260121.md
./workspace/berichte/260225.md
```
allen Directories die in den letzten 4 Wochen geändert wurden
```sh
~$ find -mtime -28 -type d
.
./.cache
./.cache/snowflake
./workspace/.cache/replit
./workspace/.local/state/replit
./workspace/.git
./workspace/.git/refs/heads
./workspace/.git/refs/remotes/origin
./workspace/.git/objects
./workspace/.git/objects/c8
./workspace/.git/objects/e9
./workspace/.git/objects/d5
........
```
allen Directories die in den letzten 4 Wochen nicht geändert wurden
```sh
~$ find -mtime +28 -type d
./.nix-defexpr
./.cache/nix
./.local
./.local/state
./.local/state/nix
./.local/state/nix/profiles
./workspace
./workspace/.cache
...........
```
allen Dateien mit der Berechtigung 644. Recherchiere was diese Berechtigung (permission flags) bedeutet.
```sh
~$ find -perm 644 -type f
./.bash_logout
./.profile
./.nix-channels
./.cache/nix/binary-cache-v6.sqlite
./.cache/nix/binary-cache-v6.sqlite-journal
./.cache/nix/fetcher-cache-v1.sqlite-journal
./.cache/nix/fetcher-cache-v1.sqlite
./workspace/.cache/replit/modules/replit.res
./workspace/.cache/replit/modules/python-3.11.res
./workspace/.cache/replit/modules.stamp
./workspace/.cache/replit/env/latest
./workspace/.cache/replit/env/latest.json
./workspace/.cache/replit/toolchain.json
```
Suche im /usr Verzeichnis nach allen Dateien die größer als 2MB sind.
```sh
~$ find /usr -size +2M
/usr/lib/locale/locale-archive
/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33
/usr/lib/x86_64-linux-gnu/libcrypto.so.3
/usr/lib/x86_64-linux-gnu/libc.so.6
/usr/lib/x86_64-linux-gnu/libperl.so.5.38.2
/usr/lib/x86_64-linux-gnu/perl/5.38.2/auto/Encode/CN/CN.so
/usr/lib/x86_64-linux-gnu/perl/5.38.2/auto/Encode/JP/JP.so
/usr/lib/x86_64-linux-gnu/perl/5.38.2/auto/Encode/KR/KR.so
/usr/lib/x86_64-linux-gnu/perl/5.38.2/CORE/charclass_invlists.h
```

Lege in ~/workspace ein Unterverzeichnis an. Erzeuge darin einige Dateien mit der Endung txt und md mit etwas Inhalt. Lösche dann mit Hilfe eines find Befehls alle txt Dateien die weniger als 10 Bytes groß sind. Wähle den Test so, dass minestens 2 Dateien gelöscht und mindestens 2 Dateien überbleiben.
Hinweis: dafür ist die -exec Option zu verwenden.

Als erstes ein Unterverzeichnis anlegen, darin die Text und markdown dateien anlegen und mit dem Befehl:
```sh
stat inhalt1.txt
```
Die Bytegrößen überprüfen und dann mit dem Befehl die Dateien löschen:
```sh
find -type f -name "*.txt" -size -10c -exec rm {} \;
```
Schreibe einen find Befehl der den Inhalt aller Dateien mit Endung md zu einem neuen md File zusammenfügt.
```sh
~/workspace$ find -type f -name "*.md" -exec cat {} + > zusammenfassung.md
cat: ./zusammenfassung.md: input file is output file
```

Zeige von allen Dateien (aber nicht Directories) im Directory /var die den Text log irgendwo im Dateinamen haben die vollständige Information (ls -l) an, die Ausgabe sieht dann ca. so aus:

…
-rw-r--r-- 1 root root 259 Apr 28  2024 /var/lib/dpkg/info/logsave.md5sums
-rw-r--r-- 1 root root 33 May 30  2024 /var/lib/dpkg/info/login.conffiles
-rwxr-xr-x 1 root root 174 May 30  2024 /var/lib/dpkg/info/login.postrm
…

```sh
~$ find /var -name "*log*.*" -exec ls -l {} \;
-rw-r--r-- 1 root root 259 Apr 28  2024 /var/lib/dpkg/info/logsave.md5sums
-rw-r--r-- 1 root root 33 May 30  2024 /var/lib/dpkg/info/login.conffiles
-rwxr-xr-x 1 root root 798 May 30  2024 /var/lib/dpkg/info/login.postinst
-rw-r--r-- 1 root root 4874 Apr 15  2025 /var/lib/dpkg/info/login.list
-rwxr-xr-x 1 root root 174 May 30  2024 /var/lib/dpkg/info/login.prerm
-rwxr-xr-x 1 root root 174 May 30  2024 /var/lib/dpkg/info/login.postrm
-rwxr-xr-x 1 root root 174 May 30  2024 /var/lib/dpkg/info/login.preinst
-rw-r--r-- 1 root root 6548 May 30  2024 /var/lib/dpkg/info/login.md5sums
-rw-r--r-- 1 root root 229 Apr 15  2025 /var/lib/dpkg/info/logsave.list
-rw-r--r-- 1 root root 7136 Oct 16 22:41 /var/log/apt/eipp.log.xz
find: ‘/var/cache/apt/archives/partial’: Permission denied
find: ‘/var/cache/ldconfig’: Permission denied
```

Folgende Übungen habe ich im Unterricht nicht mehr geschafft:

- Übung 3.5 (file)
- Übung 3.6 (cat)
- Übung 3.7 (date epoch)
