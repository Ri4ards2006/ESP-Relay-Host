# 🔌 ESP-Relay-Host

*Intelligent LLM Host Controller: Wake-on-Demand via ESP32.*

> "Hardware-level sovereignty: Wake your workstation, run your local RAG, sleep when done."

---

## 📑 Table of Contents

- [📜 The Lore](#-the-lore)
- [🛠 Tech Stack & Philosophy](#-tech-stack--philosophy)
- [📐 Architecture Overview](#-architecture-overview)
- [🚀 Roadmap](#-roadmap)
- [📊 Evaluation Metrics](#-evaluation-metrics)
- [🤝 Contributing](#-contributing)
- [⚖️ License](#-license)

## 📜 The Lore

`ESP-Relay-Host` entstand aus dem Bedarf, die Lücke zwischen einem "Always-on" Server und manuellem Einschalten zu schließen. Wir nutzen einen ESP32, um die physische Kontrolle über die Workstation zu erlangen, und kombinieren das mit einer Container-Pipeline, die nach dem Bootvorgang sofort das lokale LLM-Backend bereitstellt. Kein unnötiger Stromverbrauch, kein Cloud-Zwang, nur dedizierte KI-Inferenz genau dann, wenn man sie braucht.

## 🛠 Tech Stack & Philosophy

We marry the efficiency of embedded systems with the intelligence of modern local LLMs.

| Layer | Tool | Purpose |
| :--- | :--- | :--- |
| **Logic Core** | 🦙 Ollama | Local LLM inference (Qwen/Llama). |
| **Orchestration** | 🐋 Docker | Containerized RAG and UI management. |
| **Interface** | 🌐 Open WebUI | Local RAG knowledge base & chat UI. |
| **Hardware** | 🔌 ESP32 / Relays | Physical "On-Demand" power management. |

## 📐 Architecture Overview

```text
[Mobile/Remote] -> (API Call) -> [ESP32 Control Node]
                                         |
                                [Hardware Relay Trigger]
                                         |
                                [Desktop Server: 4060 Ti]
                                         |
                        [Docker: Ollama + Open WebUI (RAG)]
                                         |
                                [Obsidian Integration]
```

🚀 Roadmap
[x] Phase 1: Foundation - Docker setup with Ollama and Open WebUI.

[ ] Phase 2: RAG Pipeline - Obsidian-Markdown indexing and metadata alignment.

[ ] Phase 3: Remote Hardware - ESP32 firmware development for remote power triggering.

[ ] Phase 4: Feedback Loop - OLED display status for system load and LLM activity.

[ ] Phase 5: Self-Shutdown - Automatic inactivity-based idle shutdown logic.

📊 Evaluation Metrics
How do we measure success?

Energy Autonomy: Ratio of productive uptime vs. total idle power consumption.

Inference Latency: Time to first token (TTFT) on local hardware.

RAG Accuracy: Precision of retrieval from private Obsidian vaults.

Hardware Reliability: Success rate of remote wake-on-command cycles.

🤝 Contributing
Contributions are welcome!

Fork the repository.

Create your feature branch (git checkout -b feature/amazing-feature).

Commit your changes.

Push to the branch.

Open a Pull Request.

⚖️ License
This project is licensed under the MIT License. See the LICENSE file for details.
