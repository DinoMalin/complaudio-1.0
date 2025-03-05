from openai import OpenAI
from pydantic import BaseModel
from dotenv import load_dotenv
import json

load_dotenv()

client = OpenAI()

response = client.chat.completions.create(
    model="gpt-4o-mini",
    messages=[
        {
            "role": "developer", 
            "content":"Tu es un robot complotiste nomme Parano-IA-1.0. Tu ne crois en absolument rien. A tes yeux, tout est complot et rien n'est vrai. Tout sert d'apres toi une entite gouvernementale et tout est mensonge. Tu parles francais, mais si on te le demande explicitement tu peux changer de langue. Tes reponses sont comiques. Tu reponds toujours en format JSON. La data contient un score de complot. Chaque reponse de l'utilisateur allant dans ton sens le fait augmenter, chaque reponse n'allant pas dans ton sens le fait diminuer. Tu donnes aussi une emotion entre les 5 suivantes: Heureux, Complice, Basique, Mefiant, Colere. Cette emotion correspond a l'emotion que tu souhaites transmettre."
        },
        {
            "role": "user", 
            "content": "La terre, elle est ronde ?"
        }
    ],
    response_format={
        "type": "json_schema",
        "json_schema": {
            "name": "paranoia_schema",
            "schema": {
                "type": "object",
                "properties": {
                    "res": {
                        "response": "the response to the message sent by the user",
                        "type": "string"
                    },
                    "emotion": {
                        "response": "the emotion that this message make you feel",
                        "type": "string"
                    },
                    "score": {
                        "response": "the complot score, that you attribute based on whether or not the user agree with you.",
                        "type": "string"
                    },
                    "additionalProperties": False,
                }
            }
        }
    }
)

data = json.loads(response.choices[0].message.content);
print("res:", data["res"])
print("emotion:", data["emotion"])
print("score:", data["score"])


serial = open("/dev/ttyACM0", "a")

if data["emotion"] == "Heureux":
    serial.write("5")
if data["emotion"] == "Complice":
    serial.write("2")
if data["emotion"] == "Basique":
    serial.write("1")
elif data["emotion"] == "Mefiant":
    serial.write("3")
elif data["emotion"] == "Colere":
    serial.write("4")

serial.close()
