# Hotone Ampero Mini 용 MIDI Controller 개발

시간 날 때마다 사부작거리면서 개발 예정입니다.

## 계획
- **FX1, FX2, FX3, DLY, RVB ON/OFF** 제어
- **FX1, FX2, FX3, DLY, RVB 파라미터 조정용 노브 추가**
  - 세부 파라미터를 조정할 수 있도록 설계
  - 아직 MIDI 메시지에 대해 모든 정보를 확인하지 않았으므로 원하는 대로 구현 가능 여부는 미정
- **PCB 설계 및 3D 프린터 케이싱 제작** 고려 중
  - 제작 후 공유 여부 고민 중

---

## MIDI Commands for Hotone Ampero Mini MP-50

| **CC#** | **Value** | **Description**                                   |
| ------- | --------- | ------------------------------------------------- |
| 0       | 0-1       | Bank MSB: Factory/User Patch Selection            |
| 7       | 0-99      | Patch Volume                                      |
| 16      | 0-127     | Quick Access Knob 1 MSB                           |
| 17      | 0-127     | Quick Access Knob 1 LSB                           |
| 18      | 0-127     | Quick Access Knob 2 MSB                           |
| 19      | 0-127     | Quick Access Knob 2 LSB                           |
| 20      | 0-127     | Quick Access Knob 3 MSB                           |
| 21      | 0-127     | Quick Access Knob 3 LSB                           |
| 22      | 0-127     | Bank Back                                         |
| 23      | 0-127     | Bank Forward                                      |
| 24      | 0-127     | Patch Back                                        |
| 25      | 0-127     | Patch Forward                                     |
| 48      | 0-127     | FX1 Module: On (0-63) / Off (64-127)              |
| 49      | 0-127     | FX2 Module: On (0-63) / Off (64-127)              |
| 50      | 0-127     | AMP Module: On (0-63) / Off (64-127)              |
| 51      | 0-127     | NR Module: On (0-63) / Off (64-127)               |
| 52      | 0-127     | Cab Module: On (0-63) / Off (64-127)              |
| 53      | 0-127     | EQ Module: On (0-63) / Off (64-127)               |
| 54      | 0-127     | FX3 Module: On (0-63) / Off (64-127)              |
| 55      | 0-127     | DLY Module: On (0-63) / Off (64-127)              |
| 56      | 0-127     | RVB Module: On (0-63) / Off (64-127)              |
| 57      | 0-127     | Tuner: On (0-63) / Off (64-127)                   |
| 58      | 0-127     | Drum Machine Menu: On (0-63) / Off (64-127)       |
| 59      | 0-127     | Drum Machine: Stop (0-63) / Play (64-127)         |
| 60      | 0-99      | Drum Machine Rhythm Type                          |
| 61      | 0-99      | Drum Machine Volume                               |
| 62      | 0-127     | Looper: On (0-63) / Off (64-127)                  |
| 63      | 0-127     | Looper Record                                     |
| 64      | 0-127     | Looper: Stop (0-63) / Play (64-127)               |
| 65      | 0-127     | Looper Speed: Half (0-63) / Normal (64-127)       |
| 66      | 0-127     | Looper Playback: Reverse (0-63) / Normal (64-127) |
| 67      | 0-127     | Delete Loop                                       |
| 68      | 0-99      | Looper Recording Volume                           |
| 69      | 0-99      | Looper Playback Volume                            |
| 70      | 0-127     | Looper Placement: Post (0-63) / Pre (64-127)      |
| 71      | 0-127     | CTRL1: A-Red (0-63) / B-Green (64-127)            |
| 72      | 0-1       | Tempo MSB                                         |
| 73      | 0-127     | Tempo LSB                                         |
| 74      | 0-127     | CC73=0, CC74=40-127: 40-127 BPM                   |
| 75      | 0-127     | Tap Tempo                                         |
| 76      | 0-127     | Device: Lock (0-63) / Unlock (64-127)             |

---
