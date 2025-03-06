import azure.cognitiveservices.speech as speechsdk
from dotenv import load_dotenv
import os

load_dotenv()

speech_config = speechsdk.SpeechConfig(
    subscription=os.getenv("SPEECH_KEY"), region=os.getenv("REGION"))
speech_config.speech_recognition_language = "fr-FR"

audio_out = speechsdk.audio.AudioOutputConfig(use_default_speaker=True)

# A filthy shortcut because i have incomprehensible bugs with my libs.
# If your pc is normal unlike mine, consider replacing this argument with:
# use_default_microphone=True
audio_config = speechsdk.audio.AudioConfig(device_name="plughw:2,0") # fuck this man

speech_recognizer = speechsdk.SpeechRecognizer(speech_config=speech_config, audio_config=audio_config)

print("listen")
speech_recognition_result = speech_recognizer.recognize_once_async().get()
print(speech_recognition_result.text)
