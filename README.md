# A Comparison of In-Vitro Infrared (IR) Technology to Ultrasound for Guided Access of Vessels in the Upper Arm
## Abstract
Objective: IR-based devices have facilitated guided anatomical observation before surgeries like embolectomies and cannulation. Their value is still highly debated amongst scholars for reasons such as low visual quality and low improvements in rates of first attempt at completing specific procedures when compared with other imaging strategies. Because of unharnessed potential and slow innovation, IR scanners are considered novel. The object is to develop a prototype aiding comparative study of the quality of the outputs of IR and ultrasound scanners for presurgical vascular assessments. Methods: An IR scanner was developed with a 50W IR light bulb and a 16×12 IR camera sensing array. A dataset was created from images generated from the AccuVein AV300, a Caplio R7 camera, a near-IR light source, an IR-sensitive Charge-Coupled Device camera, and other high-resolution sensing equipment. The combined dataset of 30 images were converted to black-and-white and scaled in MATLAB. The Frangi “vesselness” filter focused the images on relevant anatomical details pertaining to vasculature. The quality as Signal-to-Noise Ratios (SNRs) was compared with images acquired from non-invasive ultrasound. Results: The results of the Manny-Whitney U Test was a p-value of 0.07 for the comparison of the US and IR SNRs and a p-value of 0.13 for the comparison of US and IR Peak-SNRs. The acquisition unit was limited to visualizing 192 pixels per shot. The other images were relatively high in noise. Conclusions: There was evidence to accept the null hypothesis that there was no significant difference between the IR and US modalities.

## PART 1 - DAQ
### Control - Gum images
![image](https://github.com/user-attachments/assets/4328d95d-a81a-4317-ae5a-73d9a131508b) ![image](https://github.com/user-attachments/assets/a3b5f191-7198-4f28-b150-34b1f2c90410) ![image](https://github.com/user-attachments/assets/5cc4f52b-5a0c-4a1a-bced-f45185033317)


### Control - Dorsal vein images
![image](https://github.com/user-attachments/assets/68deac56-3bbf-4034-aae7-828b3b640454) ![image](https://github.com/user-attachments/assets/b5af2834-6235-42fb-8bf3-1f2ba3f6ca49)

## PART 2 - Segmentations
### Zharov et al.
![image](https://github.com/user-attachments/assets/76ffda5d-745f-44ea-9a80-7ed1dc6d8935) ![image](https://github.com/user-attachments/assets/06627593-1c8e-4b1d-b9e1-e99c9f168c35)
Zharov, V. P., Ferguson, S., Eidt, J. F., Howard, P. C., Fink, L. M., & Waner, M. (2004). Infrared imaging of subcutaneous veins. Lasers in Surgery and Medicine: The Official Journal of the American Society for Laser Medicine and Surgery, 34(1), 56–61.
 
### From DAQ
![image](https://github.com/user-attachments/assets/f781d7e1-75c1-4f07-8295-e9bbccd4ad05) ![image](https://github.com/user-attachments/assets/8de8765f-1012-4320-9215-c83d1dc7859d)






