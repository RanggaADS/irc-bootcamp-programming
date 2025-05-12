import cv2, numpy, matplotlib
from datetime import datetime

participant_name = "Rangga Ade"

# Buka kamera
cap = cv2.VideoCapture(0)

# Cek apakah kamera berhasil dibuka
if not cap.isOpened():
    print("Tidak dapat membuka kamera.")
    exit()


while True:
    ret, frame = cap.read()
    if not ret:
        print("Gagal membaca frame.")
        break

    # Tambahkan efek mirror
    frame = cv2.flip(frame, 1)

    # Tambahkan nama peserta
    cv2.putText(frame, f"Peserta: {participant_name}", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Tambahkan waktu saat ini
    current_time = datetime.now().strftime("%H:%M:%S")
    cv2.putText(frame, f"Waktu: {current_time}", (10, 70),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 0), 2)

 

    # Tampilkan frame
    cv2.imshow("Bootcamp IRC - Kamera", frame)

    # Tekan 'q' untuk keluar
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Bersihkan
cap.release()
cv2.destroyAllWindows()
