# TODO – FreqForge (ESP32 Synthesizer)


## Phase 2 – Display (ST7789)
- [ ] SPI initialisieren
- [ ] `drivers/st7789.c/h` erstellen
- [ ] Grundfunktionen: Bildschirm löschen, Pixel setzen, Rechteck, Text
- [ ] `ui/display.c/h` anlegen (Wrapper für UI-Komponenten)
- [ ] Testanzeige: "FreqForge Boot OK"

---

## Phase 3 – Inputs (Potis & Buttons)
- [-] ADC-Konfiguration
- [-] Poti-Lesen + Glättung (Low-Pass Filter)
- [-] Buttons konfigurieren (GPIO + Pull-Up)
- [ ] Debounce einbauen
- [ ] Input-Werte auf dem Display anzeigen

---

## Phase 4 – Audio-Ausgabe
- [ ] `drivers/dac.c/h` erstellen
- [ ] I2S konfigurieren (für externen DAC)
- [ ] Buffer schreiben
- [ ] Test-Ton (Sine 440 Hz) ausgeben

---

## Phase 5 – Audio Engine
- [ ] Oszillator-Klasse erstellen (sin, square, saw)
- [ ] Phase-Accumulator implementieren
- [ ] Mixer für mehrere Stimmen
- [ ] Parameter-Struktur: freq, waveform, volume
- [ ] Störfreie Audio-Schleife (High-Priority Task)

---

## Phase 6 – UI ↔ Engine Verbindung
- [ ] Potis → Frequenz, Wellenform, Lautstärke
- [ ] Buttons → Mode/Bank/OSC auswählen
- [ ] Display → Werte live visualisieren
- [ ] Basis-Synth läuft stabil

---

## Phase 7 – System-Stabilität
- [ ] Task-Struktur optimieren:
  - [ ] Audio-Task (High)
  - [ ] UI-Task (Normal)
  - [ ] Input-Task (Low)
- [ ] Parameter-Smoothing (keine Klicks)
- [ ] SPI-Update-Frequenz optimieren (Display-FPS)
- [ ] Speicherlecks checken

---

## Phase 8 – Erweiterungen (optional)
- [ ] ADSR-Hüllkurve (Attack/Decay/Sustain/Release)
- [ ] Filter (Lowpass/Highpass)
- [ ] Delay/Chorus
- [ ] Mehrere OSC-Layer
- [ ] Presets speichern (NVS)
- [ ] Menüsystem für Einstellungen

---

## Mini-Meilensteine
- [ ] **Day 1**: Build + Blink + Logging  
- [ ] **Day 2**: Display läuft  
- [ ] **Day 3**: Inputs stabil  
- [ ] **Day 4**: DAC + 440 Hz  
- [ ] **Day 5**: Synth-Basis (OSC + Mixer + UI)